$(document).ready(function() {
    $('.details-button').on('click', function() {
        $('#customPopup').fadeIn();
    });

    $('#closePopup').on('click', function() {
        $('#customPopup').fadeOut();
    });

    $('.drama-item img').on('click', function() {
        var dramaTitle = $(this).siblings('h3').text();
        $('#popupMessage').text("Drama baru ditambahkan: " + dramaTitle);
        $('#customPopup').fadeIn();
    });
});
