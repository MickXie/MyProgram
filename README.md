# MyProgram — 程式學習資料庫

這是我在**國立臺灣海洋大學 (NTOU)** 就讀期間的個人程式學習與課程作業倉庫，涵蓋多種程式語言、資料結構、演算法、人工智慧與網頁開發。

---

## 目錄總覽

| 區域 | 語言 | 說明 |
|------|------|------|
| [C++ Primer](./cpp/cpp-primer/) | C++ | 教科書《C++ Primer 第5版》第 1–19 章練習 |
| [NTOU C++ 作業](./cpp/ntou-homework/) | C++ | 課程作業 — 撲克牌機率、遊戲、物件導向設計 |
| [APCS 競程練習](./cpp/apcs-practice/) | C++ | APCS 檢定與競程題目練習 |
| [資料結構作業](./c/data-structures/) | C | 課程作業 — 鏈結串列、樹狀結構、排序演算法 |
| [資料結構實習](./c/data-structures-practice/) | C | 實習課練習（第 1–14 週） |
| [人工智慧導論](./courses/intro-to-ai/) | C++ | 15格拼圖 A\* 搜尋求解（4 部分作業） |
| [網頁程式設計](./web/web-programming/) | HTML/CSS/JS | 課程作業（Exercise 1–11） |
| [Scoreboard App](./web/scoreboard/) | React/Vite | 獨立 React 應用程式子專案 |
| [NTOU Python 課程](./python/ntou-python/) | Python | 教科書練習（第 1–12 章）＋作業 |
| [NTOU Java 課程](./java/ntou/cs/java2026/) | Java | 物件導向練習 — BMI、撲克、員工、書單解析 |
| [Java 自學](./java/self-study/) | Java | 個人自學，與課程完全分開 |
| [MATLAB](./courses/matlab/) | MATLAB | 工程計算作業 |

---

## 目錄結構

```
MyProgram/
├── cpp/
│   ├── cpp-primer/              # C++ Primer 教科書練習，第 1–19 章
│   ├── ntou-homework/           # NTOU C++ 課程作業
│   └── apcs-practice/          # APCS 競程練習題
│
├── c/
│   ├── data-structures/         # 資料結構課程作業（C 語言）
│   └── data-structures-practice/ # 資料結構實習課（14 週）
│
├── java/
│   ├── ntou/cs/java2026/        # NTOU Java 課程（package ntou.cs.java2026）
│   │   └── docs/                # 截圖與作業繳交壓縮檔
│   └── self-study/              # 個人自學 Java（無 package 宣告）
│
├── python/
│   ├── ntou-python/             # NTOU Python 課程，第 1–12 章
│   └── experiments/             # Python 個人測試與練習
│
├── web/
│   ├── web-programming/         # 網頁程式設計課程作業，Exercise 1–11
│   ├── scoreboard/              # React + Vite 記分板應用程式
│   └── experiments/             # HTML/CSS/JS 個人測試
│
└── courses/
    ├── intro-to-ai/             # 人工智慧導論 — 15格拼圖 A* 求解器
    └── matlab/                  # MATLAB 作業
```

---

## 重點子專案

### 15格拼圖 AI 求解器
**位置：** [`courses/intro-to-ai/`](./courses/intro-to-ai/)
**語言：** C++
四部分的 A\* 搜尋演算法作業，涵蓋：可解性判斷、後繼節點生成、曼哈頓距離啟發函數、自製優先佇列。

### Scoreboard React App
**位置：** [`web/scoreboard/`](./web/scoreboard/)
**技術：** React 18 + Vite + ESLint

```bash
cd web/scoreboard
npm install
npm run dev
```

### NTOU Java 2026 — 物件導向練習
**位置：** [`java/ntou/cs/java2026/`](./java/ntou/cs/java2026/)
**語言：** Java（`package ntou.cs.java2026`）

```bash
# 從 java/ 根目錄執行
javac -cp jsoup-1.22.1.jar ntou/cs/java2026/BMICalculator.java
java -cp .:jsoup-1.22.1.jar ntou.cs.java2026.BMICalculator
```

---

## 技術棧

- **語言：** C++17、C、Java、Python 3、JavaScript、HTML5、CSS3、MATLAB
- **框架/工具：** React 18、Vite、Node.js、jsoup
- **建置工具：** Make（C++ Primer）、g++、javac
- **IDE：** VS Code、Visual Studio 2022

---

## 新增檔案規則

> 在新增任何檔案之前，請遵守以下規範，確保倉庫維持一致且整潔。

### 1. 放對資料夾

| 情境 | 放置位置 |
|------|----------|
| C++ 課程作業 | `cpp/ntou-homework/` |
| C++ 教科書練習 | `cpp/cpp-primer/` 對應章節資料夾 |
| APCS 題目 | `cpp/apcs-practice/` |
| C 資料結構正課作業 | `c/data-structures/` |
| C 資料結構實習作業 | `c/data-structures-practice/` 對應週次 |
| 學校 Java 作業 | `java/ntou/cs/java2026/`（需加 `package ntou.cs.java2026;`） |
| 個人自學 Java | `java/self-study/`（不需要 package） |
| Python 課程練習 | `python/ntou-python/` 對應章節或 `Homework/` |
| Python 個人測試 | `python/experiments/` |
| 網頁課程作業 | `web/web-programming/` |
| HTML/CSS/JS 個人練習 | `web/experiments/` |
| 跨語言課程大作業 | `courses/` 下新建子資料夾 |

### 2. 命名規範

- **資料夾：** 使用全小寫 + 連字號，例如 `my-project/`
- **C/C++ 檔案：** 使用學校格式（如 `01357043_hw1.c`）或描述性名稱
- **Java 檔案：** 使用 `PascalCase`，例如 `MyClass.java`
- **Python 檔案：** 使用 `snake_case`，例如 `my_script.py`
- **避免** 空格、中文、特殊符號出現在路徑或檔名中

### 3. 絕對不可 commit 的檔案

- `*.exe` — Windows 編譯產物
- `*.class` — Java 編譯產物
- `*.o`、`*.out` — C/C++ 編譯產物
- `node_modules/` — npm 套件
- `__pycache__/`、`*.pyc` — Python 快取
- `tempCodeRunnerFile.*` — VSCode 暫存檔
- `.DS_Store` — macOS 系統檔

### 4. 新增課程或語言

若開始一門全新課程，請在對應語言資料夾下建立子資料夾，並更新本 README 最上方的**目錄總覽**表格。

---

## 學習背景

本倉庫記錄在**國立臺灣海洋大學資訊工程學系**修課期間的課程作業與個人自學內容，包括：

- 教科書練習（《C++ Primer 第5版》）
- 各科課程評分作業
- APCS 競程練習
- 個人實驗與測試專案

> 所有程式碼均為個人原創，另有說明者除外。

---

## 如何使用本倉庫

- **想學特定語言？** 直接進入語言資料夾（`cpp/`、`c/`、`java/`、`python/`、`web/`）。
- **找課程作業？** 查看 `courses/` 或各語言資料夾下的課程子目錄。
- **想直接跑程式？** 參考上方[重點子專案](#重點子專案)的執行說明。
- **想自學 Java？** 從 [`java/self-study/`](./java/self-study/) 開始。
