const searchForm = document.querySelector("form");
const searchResultDiv = document.querySelector(".search-result");
const container = document.querySelector(".container");
let searchQuery = "";
const APP_ID = "ea6b460c";
const APP_key = "e6822c6e487c788c767eec6943ec12c4";
// console.log(container)
searchForm.addEventListener("submit", (e) => {
  e.preventDefault();
  searchQuery = e.target.querySelector("input").value;
  fetchAPI();
});

async function fetchAPI() {
  const baseURL = `https://api.edamam.com/search?q=${searchQuery}&app_id=${APP_ID}&app_key=${APP_key}&from=0&to=20`;
  const response = await fetch(baseURL);
  const data = await response.json();
  generateHTML(data.hits);
  console.log(data);
console.log(response)
}

function generateHTML(results) {
  container.classList.remove("initial");
  let generatedHTML = "";
  results.map((result) => {
    generatedHTML += `<div class="item">
    <img src="${result.recipe.image}" alt="">
    <div class="flex-container">
      <h1 class="title">${result.recipe.label}</h1>
      <a class="view-btn" href="${result.recipe.url}">View Recipe</a>
    <p class="title">Calories: ${result.recipe.calories.toFixed(2)}</p>
        <p class="item-data">Diet label: ${
          result.recipe.dietLabels.length > 0
            ? result.recipe.dietLabels
            : "No Data Found"
        }</p>
      </div>
    `
  //   `<div class="item">
  //   <img src="https://images2.minutemediacdn.com/image/upload/c_crop,h_1126,w_2000,x_0,y_181/f_auto,q_auto,w_1100/v1554932288/shape/mentalfloss/12531-istock-637790866.jpg" alt="">
  //   <div class="flex-container">
  //     <h1 class="title">This is a recipe item</h1>
  //     <a class="view-btn" href="#">View Recipe</a>
  //   </div>
  //   <p class="item-data">Calories: 120</p>
  // </div>`
  });
  searchResultDiv.innerHTML = generatedHTML;
}
