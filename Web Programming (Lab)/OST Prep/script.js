var nameError = document.getElementById('name-error');
var phoneError=document.getElementById("phone-error");
var emailError=document.getElementById("email-error");
var messageError=document.getElementById("message-error");
var submitError=document.getElementById("submit-error");

function validateName(){
    var name=document.getElementById('contact-name').value;

    if(name.length==0)
    {
        nameError.innerHTML="Name is required";
        return false;
    }
    if(!name.match(/^[A-Za-z]*\s{1}[A-Za-z]*$/))
    {
        nameError.innerHTML="Incorrect name";
        return false;
    }
    nameError.innerHTML="valid";
    return true;
}

function validatePhone(){
    var phone=document.getElementById('contact-phone').value;

    if(phone.length==0){
        phoneError.innerHTML="phone is required";
        return false;
    }
    if(phone.length!==10){
        phoneError.innerHTML="10 digits please";
        return false;
    }
    if(!phone.match(/^[0-9]{10}$/)){
        phoneError.innerHTML="only digits please";
        return false;
    }
    phoneError.innerHTML="valid";
    return true;

}
function validateEmail(){
    var email=document.getElementById('contact-email').value;

    if(email.length==0){
        emailError.innerHTML="enter email";
        return false;
    }
    if(!email.match(/^[a-z\._\-[0-9]*[@][a-z]*[\.][a-z]{2,4}$/))
    {
        emailError.innerHTML="email invalid";
        return false;
    }
    emailError.innerHTML="valid";
    return true;
}
function validateMessage(){
    var message=document.getElementById('contact-message').value;
    
    if(message.length==0){
        messageError.innerHTML="enter message";
        return false;
    }
    var required=20;
    var left=required-message.length;
    if(left>0){
        messageError.innerHTML=left  +  "more characters required"
        return false;
    }
    messageError.innerHTML="valid"
    return true;

}
function validateForm(){
    if(!validateName() || !validatePhone() || !validateEmail() || !validateMessage()){
        submitError.innerHTML="please fix error";
        return false;
    }
    else{
        windows.location.href("index.html");
        return true;
    }

}