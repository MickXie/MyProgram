import { useState, useEffect } from "react";
import Axios from "axios";
import "./App.css";

function App() {
  const [redScore, setRedScore] = useState(0);
  const [blueScore, setBlueScore] = useState(0);
  const MAX = 11;

  const [fact, setFact] = useState("");

  const handleRedClick = () => {
    if (redScore < MAX && blueScore < MAX) {
      setRedScore(redScore + 1);
    }
  };

  const handleBlueClick = () => {
    if (redScore < MAX && blueScore < MAX) {
      setBlueScore(blueScore + 1);
    }
  };

  const winner =
    redScore === MAX ? "紅隊 獲勝" :
    blueScore === MAX ? "藍隊 獲勝" :
    "";

  const resetScore = () => {
    setRedScore(0);
    setBlueScore(0);
  };
  const fetchFact = () => {
    Axios.get("https://catfact.ninja/fact")
      .then((res) => {
        console.log(res.data);
        setFact(res.data.fact);
      })
      .catch((err) => {
        console.error("API Error:", err);
        setFact("取得資料失敗，請再試一次！");
      });
  };

  useEffect(() => {
    fetchFact();
  }, []);

  return (
    <div className="wrapper">
      <h1>計分板</h1>

      <div className="scoreboard">
        <div className="team red" onClick={handleRedClick}>
          {redScore}
        </div>
        <div className="team blue" onClick={handleBlueClick}>
          {blueScore}
        </div>
      </div>

      {winner && <h2 className="winner">{winner}</h2>}
      <button className="reset" onClick={resetScore}>重置</button>

      <div className="result-box">
        <p className="fact-text">{fact}</p>
        <button className="reload-btn" onClick={fetchFact}>
          重抓一次
        </button>
      </div>
    </div>
  );
}

export default App;
