// app.js

// function openModal() {
//     var modal = document.getElementById("add-friend-modal");
//     modal.style.display = "block";
//   }
  
//   function closeModal() {
//     var modal = document.getElementById("add-friend-modal");
//     modal.style.display = "none";
//   }
  
//   function searchFriend() {
//     var friendUsername = document.getElementById("friend-username").value;
//     var searchResults = document.getElementById("search-results");
  
//     // Perform friend search logic here
//     // You can use AJAX to send the friendUsername to the server and get results
//     // For this example, let's just add a simple result to the searchResults div
//     var resultDiv = document.createElement("div");
//     resultDiv.textContent = "Result: " + friendUsername;
//     searchResults.appendChild(resultDiv);
//   }
// friend-interaction.js

// Get all friend items
// friend-interaction.js

// Get all friend items
// friend-interaction.js

// Get all friend items
function switchChat(friendName, lastMessage) {
  const currentFriendName = document.getElementById('current-friend-name');
  const chatContent = document.getElementById('chat-content');

  currentFriendName.textContent = friendName;
  chatContent.innerHTML = `<div class="messages">
                              <div class="sent">
                                <img class="avatar" src="img/me.webp" alt="Sent Avatar">
                                ${lastMessage}
                              </div>
                              <div class="received">
                                <img class="avatar" src="img/${friendName.toLowerCase()}.webp" alt="Received Avatar">
                                Example received message
                              </div>
                            </div>`; // You can replace this with your actual chat message retrieval logic
}

// Add click event listeners to friend items
const friendItems = document.querySelectorAll('.friend-item');
friendItems.forEach((friendItem) => {
  friendItem.addEventListener('click', () => {
    friendItems.forEach((item) => {
      item.classList.remove('selected');
    });

    friendItem.classList.add('selected');

    const friendName = friendItem.querySelector('h3').textContent;
    const lastMessage = friendItem.querySelector('p').textContent;
    switchChat(friendName, lastMessage);
  });
});




function openModal() {
  var modal = document.getElementById("add-friend-modal");
  modal.style.display = "block";
}

function closeModal() {
  var modal = document.getElementById("add-friend-modal");
  modal.style.display = "none";
}

function searchFriend() {
  var friendUsername = document.getElementById("friend-username").value;
  var searchResults = document.getElementById("search-results");

  // Clear previous search results
  searchResults.innerHTML = "";

  // Perform friend search logic here using AJAX
  var xhr = new XMLHttpRequest();
  xhr.onreadystatechange = function() {
    if (xhr.readyState === XMLHttpRequest.DONE) {
      if (xhr.status === 200) {
        // Parse the JSON response from the server
        var response = JSON.parse(xhr.responseText);

        // Iterate through the results and create result divs
        response.forEach(function(result) {
          var resultDiv = document.createElement("div");
          resultDiv.textContent = "Result: " + result.username;
          searchResults.appendChild(resultDiv);
        });
      } else {
        console.error("Error fetching search results");
      }
    }
  };

  // Replace 'your-search-endpoint' with the actual endpoint on your server
  var endpoint = 'your-search-endpoint?username=' + encodeURIComponent(friendUsername);
  xhr.open("GET", endpoint, true);
  xhr.send();
}

  