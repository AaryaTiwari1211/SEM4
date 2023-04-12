function login() {
    var username = document.getElementById("username").value;
    var password = document.getElementById("password").value;

    if (username == "" || password == "") {
        alert("Please fill in all fields.");
    } else if (username == "admin" && password == "password") {
        alert("Login successful!");
    } else {
        alert("Invalid username or password.");
    }
}
