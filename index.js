const menuIcon = document.querySelector(".hamburger")
const menu = document.querySelector(".nav--links")
menuIcon.addEventListener("click",()=>{
    if(menu.style.display == "flex")
        menu.style.display = "none"
    else
        menu.style.display = "flex"
})