/**
 * On load
 *
 * 1.) Assign colors to boxes (Each color twice).
 * 2.) 4*4 => 16 boxes  ==> 16 colors.
 * 3.) Randomize the colors of the boxes.
 * 4.) Hide the colors Initially.
 * 5.) Color should reveal on click.
 * 6.) If user clicks on 2 boxes
 *   6.1) Colors are different, they should HIDE.
 *   6.2) Colors are same, they should FREEZE.
 *
 *
 *
 *
 * **/

const colors = ["#ad1aac", "#00a4e4", "#e1261c", "#7b8994", "#a99260", "#6534ac", "#ffc907", "#00dc06"];
const boxes = document.getElementsByClassName("box");
var timer = document.querySelector(".timer");
var startBtn = document.querySelector(".start_btn");
var clickedBoxes = [];

function addId(i) {
  boxes[i].id = "box" + i;
}

function assignColor(i) {
  if (i < colors.length) {
    boxes[i].style = `background-color:${colors[i]}`;
  } else {
    boxes[i].style = `background-color:${colors[15 - i]}`;
  }
}

function randomizeColor(i) {
  boxes[i].style.order = parseInt(Math.random() * 100);
}

function checkBoxColor() {
  if (clickedBoxes.length == 2 && clickedBoxes.length > 0) {
    let audio;
    let box1 = document.getElementById(clickedBoxes[0]);
    let box2 = document.getElementById(clickedBoxes[1]);

    if (window.getComputedStyle(box1).getPropertyValue("background-color") !== window.getComputedStyle(box2).getPropertyValue("background-color")) {
      audio = new Audio("utils/sound/wrong.mp3");
      audio.play();
      setTimeout(() => {
        box1.classList.add("hideColor");
        box2.classList.add("hideColor");
      }, 500);
    } else {
      if (box1.id !== box2.id) {
        audio = new Audio("utils/sound/succeed.wav");
        audio.play();
      }
    }

    clickedBoxes = [];
  }
}

function clickHandler(i) {
  boxes[i].addEventListener("click", () => {
    if (boxes[i].classList.contains("hideColor")) {
      clickedBoxes.push(boxes[i].id);
      boxes[i].classList.remove("hideColor");

      checkBoxColor();
    }
  });
}

function timerFun() {
  var sec = 0;
  var min = 0;
  setInterval(() => {
    sec++;
    if (sec > 59) {
      sec = 0;
      min++;
    }
    timer.innerHTML = `<p>${min}m  ${sec}s</p>`;
  }, 1000);
}

function init() {
  for (let i = 0; i < boxes.length; i++) {
    addId(i);
    assignColor(i);
    randomizeColor(i);
    clickHandler(i);
  }
}

init();
startBtn.addEventListener("click", (e) => {
  timerFun();
  startBtn.style = "display:none";
});
