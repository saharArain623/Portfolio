const sentences = [
  "JavaScript is a powerful programming language",
  "Practice makes a man perfect",
  "Frontend development is fun and creative"
];

let startTime, timer;

function startTest() {
  let random = sentences[Math.floor(Math.random() * sentences.length)];
  document.getElementById("sentence").innerText = random;

  document.getElementById("input").value = "";
  document.getElementById("result").innerText = "";

  startTime = new Date().getTime();

  timer = setInterval(updateTime, 1000);
}

function updateTime() {
  let currentTime = new Date().getTime();
  let seconds = Math.floor((currentTime - startTime) / 1000);
  document.getElementById("time").innerText = "Time: " + seconds;
}

document.getElementById("input").addEventListener("input", function () {
  let inputText = this.value;
  let originalText = document.getElementById("sentence").innerText;

  if (inputText === originalText) {
    clearInterval(timer);

    let endTime = new Date().getTime();
    let totalTime = (endTime - startTime) / 1000;

    let words = inputText.split(" ").length;
    let wpm = Math.round((words / totalTime) * 60);

    document.getElementById("result").innerText = "WPM: " + wpm;
  }
});