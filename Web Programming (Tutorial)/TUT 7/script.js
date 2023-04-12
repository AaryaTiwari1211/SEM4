var img1 = document.getElementsByClassName('img')[0]
var img2 = document.getElementsByClassName('img')[1]
var img3 = document.getElementsByClassName('img')[2]

function function1() {
    img1.style.opacity = '0.4'
}
function function2() {
    img2.style.width = '100px'
    img2.style.height = '100px'
}
function function3() {
    img3.style.border = '5px solid black'
    img3.style.borderRadius = '100px'
}

var text = document.getElementById('text1')
var count = 0
function textFunction() {
    if(count%3===0)
    {
        text.innerHTML = 'This is Dhairya'
        count++
    }
    else if(count%3===1)
    {
        text.innerHTML = 'This is Aarya'
        count++
    }
    else
    {
        text.innerHTML = 'This is Aditya'
        count++
    }
}
