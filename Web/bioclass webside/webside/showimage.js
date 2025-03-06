// The video
let sto = document.querySelector("#stop");
let video;
// For displaying the label
let label = "waiting...";
let running = false;
// The classifier
let classifier;
let modelURL = "https://teachablemachine.withgoogle.com/models/RpLP26mR2/";
new p5();
let colse = 1;
let can;

// Load the model!
function preload() {
  classifier = ml5.imageClassifier(modelURL + "model.json");
}
function classifyVideo() {
  classifier.classify(video, gotResults);
}
function Start() {
  se();
  dr();
  classifyVideo();
  colse = 1;
  sto.style.display = "inline-block";
}
function pausecanva() {
  colse = 0;
}
//set up

function se() {
  // setup 程式碼
  can = createCanvas(640, 520);
  can.parent("Acanva");
  // Create the video
  video = createCapture(VIDEO);
  video.hide();
  //  Start classifying
  classifyVideo();
}

function dr() {
  // draw 程式碼
  background(0);
  // Draw the video
  image(video, 0, 0);
  textSize(32);
  textAlign(CENTER, CENTER);
  fill(255);
  text(label, width / 2, height - 16);
  // code for draw loop goes here
}

// Add a button to stop the camera and classification

function stopDrawing() {
  video.stop();
  noLoop();
  canvas.remove();
  colse = 0;
  sto.style.display = "none";
}
//  Get the classification
function gotResults(error, results) {
  // Something went wrong!
  if (error) {
    console.error(error);
    return;
  }
  // Store the label and classify
  console.log(results[0].label);
  var rcon = Math.round(results[0].confidence * 100) / 100;
  rcon = rcon * 100;
  rcon = rcon + "%";
  label = results[0].label + "  " + rcon;
  if (colse == 1) {
    classifyVideo();
    dr();
  }
}
