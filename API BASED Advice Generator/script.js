let advice = document.querySelector(".advice");
let btn = document.querySelector(".btn");

btn.addEventListener("click", () => {
    getNewAdvice();
});

getNewAdvice = async () => {
    const url = "https://api.adviceslip.com/advice";
    const response = await fetch(url);
    const data = await response.json();
    advice.innerHTML = data.slip.advice;
};

getNewAdvice();