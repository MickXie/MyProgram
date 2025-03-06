let phDiv = document.querySelector(".hcp");
let AIDiv = document.querySelector(".AI");
let alDiv = document.querySelector(".va");
let hb = document.querySelector("#homebt");
let vb = document.querySelector("#viewbt");
let Ab = document.querySelector("#AIbt");
let cimg = document.querySelector("#contentimage");
let ctt = document.querySelector("#ctt");
let ctc = document.querySelector("#ctc");
let x = 0;
function ph() {
  phDiv.style.display = "block";
  phDiv.style.display = "flex";
  alDiv.style.display = "none";
  AIDiv.style.display = "none";
  hb.style.textDecoration = "underline";
  vb.style.textDecoration = "none";
  Ab.style.textDecoration = "none";
}
function pv() {
  alDiv.style.display = "block";
  alDiv.style.display = "flex";
  phDiv.style.display = "none";
  AIDiv.style.display = "none";
  vb.style.textDecoration = "underline";
  hb.style.textDecoration = "none";
  Ab.style.textDecoration = "none";
}

function pA() {
  AIDiv.style.display = "inline-block";
  phDiv.style.display = "none";
  alDiv.style.display = "none";
  Ab.style.textDecoration = "underline";
  hb.style.textDecoration = "none";
  vb.style.textDecoration = "none";
}
