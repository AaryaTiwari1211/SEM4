function login() {
    var username_login = document.getElementById("usernamel").value;
    var password_login = document.getElementById("passwordl").value;

    if (username_login == "" || password_login == "") {
        alert("Please fill in all fields.");
    } else if (username_login == "admin" && password_login == "password") {
        alert("Login successful!");
    } else {
        alert("Invalid username or password.");
    }
}

