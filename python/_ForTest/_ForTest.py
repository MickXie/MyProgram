import cv2
import numpy as np
import tensorflow as tf

MODEL_URL = "https://teachablemachine.withgoogle.com/models/RpLP26mR2/"  # 換成你的 model URL
MODEL_PATH = "tm_model/model.h5"
LABEL_PATH = "tm_model/labels.txt"

running = False
label_text = "waiting..."


# 下載模型（只需第一次）
def download_model():
    import os, requests, zipfile, io

    if not os.path.exists("tm_model"):
        print("Downloading model...")
        os.makedirs("tm_model", exist_ok=True)

        # Teachable Machine 的下載 URL
        zip_url = MODEL_URL + "model.zip"
        r = requests.get(zip_url)

        z = zipfile.ZipFile(io.BytesIO(r.content))
        z.extractall("tm_model")

        print("Model download completed.")


# 載入模型
def load_model():
    model = tf.keras.models.load_model(MODEL_PATH)

    with open(LABEL_PATH, "r") as f:
        labels = f.read().splitlines()

    return model, labels


# 執行分類
def classify_frame(model, labels, frame):
    img = cv2.resize(frame, (224, 224))         # TM 預設尺寸
    img = img.astype(np.float32) / 255.0
    img = np.expand_dims(img, axis=0)

    prediction = model.predict(img)[0]
    idx = np.argmax(prediction)
    confidence = prediction[idx]

    return labels[idx], confidence


# 主流程
def run_video():
    global running, label_text

    running = True

    print("Loading Teachable Machine model...")
    download_model()
    model, labels = load_model()
    print("Model loaded!")

    cap = cv2.VideoCapture(0)

    while running:
        ret, frame = cap.read()
        if not ret:
            break

        # 做分類
        label, conf = classify_frame(model, labels, frame)
        label_text = f"{label} {conf*100:.2f}%"

        # 顯示影像
        cv2.putText(frame, label_text, (20, 40),
                    cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)

        cv2.imshow("Teachable Machine Classifier", frame)

        # 按 q 退出
        key = cv2.waitKey(1)
        if key == ord('q'):
            running = False

    cap.release()
    cv2.destroyAllWindows()


if __name__ == "__main__":
    run_video()


# 
#                        _oo0oo_
#                       o8888888o
#                       88" . "88
#                       (| -_- |)
#                       0\  =  /0
#                     ___/`---'\___
#                   .' \\|     |// '.
#                  / \\|||  :  |||// \
#                 / _||||| -:- |||||- \
#                |   | \\\  -  /// |   |
#                | \_|  ''\---/''  |_/ |
#                \  .-\__  '-'  ___/-. /
#              ___'. .'  /--.--\  `. .'___
#           ."" '<  `.___\_<|>_/___.' >' "".
#          | | :  `- \`.;`\ _ /`;.`/ - ` : | |
#          \  \ `_.   \_ __\ /__ _/   .-` /  /
#      =====`-.____`.___ \_____/___.-`___.-'=====
#                        `=---='
# 
# 
#      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# 
#                佛祖保佑         永无BUG

