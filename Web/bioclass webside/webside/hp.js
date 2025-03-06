function changer() {
  x++;
  if (x > 32) {
    x = 0;
  }
  changim();
}
function changel() {
  x--;
  if (x < 0) {
    x = 32;
  }
  changim();
}
function changim() {
  if (x == 0) {
    cimg.src = "./classpicture/1.png";
    ctt.textContent = "四點素尺蛾";
    ctc.textContent =
      "本種展翅長約 32-40 mm，觸角絲狀、黃褐色，整體粉白色，前翅寬，前緣黃褐色，頂角直角狀，外緣向外彎，翅身密佈細黑點斑，端室斑呈小黑點斑，後中線呈灰色橫線紋，後翅寬，紋路同前翅者，端室斑較前翅者稍大。棲息於低海拔森林帶，成蟲主要發生於夏秋季。";
  } else if (x == 1) {
    cimg.src = "./classpicture/2.png";
    ctt.textContent = "雌黃粉尺蛾";
    ctc.textContent =
      "50mm，體色鮮艷，雄蛾前翅橙黃色或橙紅色具橙黃色的碎斑，翅端有一枚不明顯的黃斑，雌蛾顏色較淡，黃褐色具不明顯的褐色斑紋。白天常以倒掛的方式停棲葉背，在林中走動時常被驚動飛起，不久又鑽進葉背躲藏，有些個體夜晚會趨光。";
  } else if (x == 2) {
    cimg.src = "./classpicture/3.png";
    ctt.textContent = "台灣瑟弄蝶";
    ctc.textContent =
      "中型弄蝶。軀體褐色。翅面底色褐色。前翅中央有一黃白斑列，其中幾個特定位置的黃白斑較為大型，其餘則較小。後翅有一列黑褐色小斑形成的弧形斑列。前翅緣毛褐色，後翅緣毛黑白相間。主要棲息在常綠闊葉森林，有時在都市綠地發生。一年多代。成蟲於林緣、溪流邊等場所活動，飛行敏捷靈活，有訪花性。雄蝶會至濕地吸水。休息時翅平展。幼蟲取食多種樟科植物葉片，如樟樹、錫蘭肉桂、豬腳楠、黃肉樹(小梗黃肉楠)等。冬季以幼蟲態過冬。";
  } else if (x == 3) {
    cimg.src = "./classpicture/4.png";
    ctt.textContent = "巾夜蛾";
    ctc.textContent =
      "展翅50mm，翅面淡灰褐色具淺紫色調，前翅中、外線黑褐色，外線至頂角具黑色褐色斑相連，端部二分頂角，翅面黑褐色的角狀斑下緣於各脈上具波狀紋。低中海拔原生、次生林，偶見。";
  } else if (x == 4) {
    cimg.src = "./classpicture/5.png";
    ctt.textContent = "中南裳蛾";
    ctc.textContent =
      "展翅47-48mm，外觀渾圓厚實，翅面灰褐色，外觀近似斷線南夜蛾但本種前翅頂角的黑斑及外線明顯，亞端線前後端具黑斑，中間顏色較淡，斷線南夜蛾亞端線為黑褐色糊狀連續波浪紋。";
  } else if (x == 5) {
    cimg.src = "./classpicture/6.png";
    ctt.textContent = "白點卡裳蛾";
    ctc.textContent =
      "本種前翅長約 12 mm，頭部與體軀主色為白灰色參暗揮褐色，頸片暗灰褐色；前翅底色暗褐色，中央區塊參濃密白灰色，腎紋白灰色外框暗褐色，後翅暗褐色，後半段參白灰色。無外觀近似種，辨識容易。";
  } else if (x == 6) {
    cimg.src = "./classpicture/7.png";
    ctt.textContent = "弧緣貧裳蛾";
    ctc.textContent =
      "本種前翅長約 15-16 mm，胸部、體軀與前翅深褐色或褐色，雄蟲前翅稍狹長，前緣中段向內微凹，頂角圓鈍，外緣平直或些微內彎；腎紋呈微小黑點斑，亞外緣線黃褐色近平直，其基側具棕黑暈，外側至外緣區間滿佈灰褐色鱗；後翅寬，頂角圓鈍，翅身基半部淡灰褐色而向外緣漸暗呈棕色，亞外線線黃褐色於近內緣1/4段向內折曲而言沿外緣平行向內緣側至臀角止，亞外緣線與外緣間滿佈灰褐色鱗片；雌蟲紋路與雄蟲無顯著差異，然前翅前緣平直，頂角圓鈍，外緣微向外彎。本種為常見種，棲息於低中海拔山區，推側一年多世代，成蟲幾乎全年可見。";
  } else if (x == 7) {
    cimg.src = "./classpicture/8.jpg";
    ctt.textContent = "曲帶浮裳蛾(長鬚裳蛾)";
    ctc.textContent =
      "本種展翅長約 33 mm，前翅長約 17 mm，下唇鬚長於向前方延伸，停棲時整體呈三角形，觸角絲狀，約前翅前緣一半長度，雌雄異型，體軀與前翅主色於雄蟲棕色而雌蟲黑棕色，後翅淡褐色而向外緣色調趨暗；前翅頂角尖突，外緣近頂角1/3段向基側凹，雄蟲前翅前中線呈暗棕色弧形向外圓弧彎曲，中室外緣具橫向米白色弧形向基側凹之線紋，後中線暗棕色走向略與外緣同，亞外緣各脈間具有暗棕色點斑，亞外緣至外緣間色調稍淡於其餘區間；雌蟲前翅前緣至亞前緣間呈淡褐色，後中線呈米白色走向略與外緣同。無外觀近似種，辨識容易。主要棲息於1500至3100公尺森林，少數紀錄於中部800公尺山區。";
  } else if (x == 8) {
    cimg.src = "./html/arrowl.png";
    ctt.textContent = "FF9";
    ctc.textContent = "ff9";
  } else if (x == 9) {
    cimg.src = "./html/arrowl.png";
    ctt.textContent = "FF10";
    ctc.textContent = "ff10";
  } else if (x == 10) {
    cimg.src = "./html/arrowl.png";
    ctt.textContent = "FF11";
    ctc.textContent = "ff11";
  } else if (x == 11) {
    cimg.src = "./html/arrowl.png";
    ctt.textContent = "FF12";
    ctc.textContent = "ff12";
  } else if (x == 12) {
    cimg.src = "./html/arrowl.png";
    ctt.textContent = "FF13";
    ctc.textContent = "ff13";
  } else if (x == 13) {
    cimg.src = "./html/arrowl.png";
    ctt.textContent = "FF14";
    ctc.textContent = "ff14";
  } else if (x == 14) {
    cimg.src = "./html/arrowl.png";
    ctt.textContent = "FF15";
    ctc.textContent = "ff15";
  } else if (x == 15) {
    cimg.src = "./html/arrowl.png";
    ctt.textContent = "FF16";
    ctc.textContent = "ff16";
  } else if (x == 16) {
    cimg.src = "./html/arrowl.png";
    ctt.textContent = "FF17";
    ctc.textContent = "ff17";
  } else if (x == 17) {
    cimg.src = "./html/arrowl.png";
    ctt.textContent = "FF18";
    ctc.textContent = "ff18";
  } else if (x == 18) {
    cimg.src = "./html/arrowl.png";
    ctt.textContent = "FF19";
    ctc.textContent = "ff19";
  } else if (x == 19) {
    cimg.src = "./html/arrowl.png";
    ctt.textContent = "FF20";
    ctc.textContent = "ff20";
  } else if (x == 20) {
    cimg.src = "./html/arrowl.png";
    ctt.textContent = "FF21";
    ctc.textContent = "ff21";
  } else if (x == 21) {
    cimg.src = "./html/arrowl.png";
    ctt.textContent = "FF22";
    ctc.textContent = "ff22";
  } else if (x == 22) {
    cimg.src = "./html/arrowl.png";
    ctt.textContent = "FF23";
    ctc.textContent = "ff23";
  } else if (x == 23) {
    cimg.src = "./html/arrowl.png";
    ctt.textContent = "FF24";
    ctc.textContent = "ff24";
  } else if (x == 24) {
    cimg.src = "./html/arrowl.png";
    ctt.textContent = "FF25";
    ctc.textContent = "ff25";
  } else if (x == 25) {
    cimg.src = "./html/arrowl.png";
    ctt.textContent = "FF26";
    ctc.textContent = "ff26";
  } else if (x == 26) {
    cimg.src = "./html/arrowl.png";
    ctt.textContent = "FF27";
    ctc.textContent = "ff27";
  } else if (x == 27) {
    cimg.src = "./html/arrowl.png";
    ctt.textContent = "FF28";
    ctc.textContent = "ff28";
  } else if (x == 28) {
    cimg.src = "./html/arrowl.png";
    ctt.textContent = "FF29";
    ctc.textContent = "ff29";
  } else if (x == 39) {
    cimg.src = "./html/arrowl.png";
    ctt.textContent = "FF30";
    ctc.textContent = "ff30";
  } else if (x == 30) {
    cimg.src = "./html/arrowl.png";
    ctt.textContent = "FF31";
    ctc.textContent = "ff31";
  } else if (x == 31) {
    cimg.src = "./html/arrowl.png";
    ctt.textContent = "FF32";
    ctc.textContent = "ff32";
  }
}
