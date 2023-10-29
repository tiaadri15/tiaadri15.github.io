document.addEventListener("DOMContentLoaded", function () {
    const themeToggle = document.getElementById("themeToggle");
    const body = document.body;
    const alertContainer = document.getElementById("alertContainer");
    const alertMessage = document.getElementById("alertMessage");
    const closeAlert = document.getElementById("closeAlert");
    const logoutButton = document.getElementById("logoutButton");

    themeToggle.addEventListener("click", () => {
        body.classList.toggle("dark-mode");

        if (body.classList.contains("dark-mode")) {
            showAlert("Dark Mode", "Anda telah berganti ke mode gelap.");
        } else {
            showAlert("Light Mode", "Anda telah berganti ke mode terang.");
        }
    });

    closeAlert.addEventListener("click", () => {
        alertContainer.style.display = "none";
    });

    function showAlert(title, message) {
        alertMessage.innerHTML = `<strong>${title}</strong><br>${message}`;
        alertContainer.style.display = "block";
    }

    const notificationItem = document.getElementById("notificationItem");

    notificationItem.addEventListener("click", function () {
        showNotification("Anda memiliki pesan baru!");
    });

    function showNotification(message) {
        const notification = document.createElement("div");
        notification.className = "notification-popup";
        notification.textContent = message;
        document.body.appendChild(notification);

        setTimeout(function () {
            document.body.removeChild(notification);
        }, 3000); 
    }

    logoutButton.addEventListener("click", function (e) {
        e.preventDefault();

        if (confirm("Apakah Anda yakin ingin logout?")) {
            window.location.href = "logout.php";
        }
    });
});

