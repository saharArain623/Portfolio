
    // Dark Mode Toggle
    const toggleBtn = document.getElementById("themeToggle");

    toggleBtn.onclick = () => {
        document.body.classList.toggle("dark-mode");

        if (document.body.classList.contains("dark-mode")) {
            toggleBtn.innerHTML = '<i class="fas fa-sun"></i>';
        } else {
            toggleBtn.innerHTML = '<i class="fas fa-moon"></i>';
        }
    };

    // Typing Animation
    const text = ["Web Developer", "Programmer"];
    let i = 0;
    let j = 0;
    let currentText = "";
    let isDeleting = false;

    function type() {
        const typeDelay = 300;   // typing speed slower
        const deleteDelay = 150; // deleting speed

        if (i < text.length) {
            if (!isDeleting && j <= text[i].length) {
                currentText = text[i].substring(0, j++);
            } else if (isDeleting && j >= 0) {
                currentText = text[i].substring(0, j--);
            }

            document.getElementById("typing").innerHTML = currentText;

            if (j == text[i].length) {
                isDeleting = true;
                setTimeout(type, 1000); // pause before deleting
                return;
            }

            if (j == 0) {
                isDeleting = false;
                i++;
                if (i == text.length) {
                    i = 0;
                }
            }

            setTimeout(type, isDeleting ? deleteDelay : typeDelay);
        }
    }

    // Start typing
    type();
    AOS.init();


(function(){
  emailjs.init("aw6eEXNyWYUKKhiV6");
})();

document.getElementById("contact-form")
.addEventListener("submit", function(e) {
  e.preventDefault();

  emailjs.sendForm(
    "service_yfat94f",
    "template_spjsjfh",
    this
  ).then(() => {
    alert("Message sent ✅");
  }).catch((error) => {
    console.log(error);
    alert("Error ❌");
  });
});

