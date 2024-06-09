let addedPlayers = [];

const loadPlayerData = async (searchText, dataLimit) => {
  const url = `https://www.thesportsdb.com/api/v1/json/3/searchplayers.php?p=${searchText}`;
  const res = await fetch(url);
  const data = await res.json();
  displayPlayerData(data.player, dataLimit);
};

const displayPlayerData = (players, dataLimit) => {
  const playerContainer = document.getElementById("card-container");
  playerContainer.textContent = "";
  const showAll = document.getElementById("show-all");

  if (dataLimit && players.length > 9) {
    players = players.slice(0, 9);
    showAll.classList.remove("hidden");
  } else {
    showAll.classList.add("hidden");
  }

  const noPlayer = document.getElementById("no-player");
  if (players.length === 0) {
    noPlayer.classList.remove("hidden");
  } else {
    noPlayer.classList.add("hidden");
  }

  players.forEach((player) => {
    const playerDiv = document.createElement("div");
    playerDiv.classList.add("col");
    playerDiv.innerHTML = `
      <div class="card h-fit bg-base-100 shadow-xl">
        <figure>
          <img
            class="w-full h-full"
            src="${
              player.strThumb
                ? player.strThumb
                : "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQX23gnZGjKJpwK7YwZPBkWO1IJsp8QZui6VA&s "
            }"
            alt="${player.strPlayer}"
          />
        </figure>
        <div class="card-body">
          <h2 class="card-title">${player.strPlayer}</h2>
          <p class="text-xl">Gender: ${player.strGender}</p>
          <p class="text-xl">Date of Birth: ${player.dateBorn}</p>
          <p class="text-xl">Birth Place: ${player.strBirthLocation}</p>
          <p class="text-xl">Nationality: ${player.strNationality}</p>
          <div class="social-media gap-5 flex mt-5">          
            <a class="" href="${player.strFacebook}" target="_blank">
              <i class="text-blue-600 text-3xl fa-brands fa-facebook"></i>
            </a>
            <a href="${player.strTwitter}" target="_blank">
              <i class="text-blue-600 text-3xl fa-brands fa-twitter"></i>
            </a>
            <a href="${player.strInstagram}" target="_blank">
              <i class="text-red-600 text-3xl fa-brands fa-instagram"></i>
            </a>
          </div>
          <div class="card-actions justify-end">
            <button class="btn-sm text-white bg-red-400" id="add-${
              player.idPlayer
            }" onclick="addPlayer('${player.strPlayer}', 'add-${
      player.idPlayer
    }')">add</button>   
            <button class="btn-sm text-white bg-green-400" onclick="loadPlayerDetails('${
              player.idPlayer
            }')">details</button>
          </div>
        </div>
      </div>
    `;
    playerContainer.appendChild(playerDiv);
  });
  toggleSpinner(false);
};

const processSearch = (dataLimit) => {
  const searchField = document.getElementById("search-field");
  const searchText = searchField.value;
  loadPlayerData(searchText, dataLimit);
};

document.getElementById("click-btn").addEventListener("click", () => {
  toggleSpinner(true);
  processSearch(10);
});

document.getElementById("search-field").addEventListener("keypress", (e) => {
  if (e.key === "Enter") {
    toggleSpinner(true);
    processSearch(10);
  }
});

const toggleSpinner = (isLoading) => {
  const loaderSection = document.getElementById("loader");
  if (isLoading) {
    loaderSection.classList.remove("hidden");
  } else {
    loaderSection.classList.add("hidden");
  }
};

document.getElementById("btn-showAll").addEventListener("click", () => {
  processSearch();
});

const loadPlayerDetails = async (id) => {
  const url = `https://www.thesportsdb.com/api/v1/json/3/lookupplayer.php?id=${id}`;
  const res = await fetch(url);
  const data = await res.json();
  displayPlayerDetails(data.players[0]);
};

const displayPlayerDetails = (player) => {
  const modalContent = document.getElementById("modal-content");
  modalContent.innerHTML = `
    <h3 class="font-bold text-lg">${player.strPlayer}</h3>
    <p class="py-4">Gender: ${player.strGender}</p>
    <p class="py-4">Date of Birth: ${player.dateBorn}</p>
    <p class="py-4">Birth Place: ${player.strBirthLocation}</p>
    <p class="py-4">Nationality: ${player.strNationality}</p>
  `;
  document.getElementById("my_modal_3").showModal();
};

const addPlayer = (playerName, buttonId) => {
  if (addedPlayers.length < 11) {
    addedPlayers.push(playerName);
    updateTotalPlayersList();
    document.getElementById(buttonId).disabled = true;
  } else {
    document.getElementById("warning_modal").showModal();
  }
};

const updateTotalPlayersList = () => {
  const totalPlayersList = document.getElementById("total-players-list");
  totalPlayersList.innerHTML = "";
  addedPlayers.forEach((player) => {
    const li = document.createElement("li");
    li.textContent = player;
    totalPlayersList.appendChild(li);
  });
  document.getElementById("total-player-count").textContent =
    addedPlayers.length;
};

loadPlayerData("Messi", 9);
