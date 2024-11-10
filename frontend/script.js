document.getElementById("requestForm").addEventListener("submit", function (e) {
    e.preventDefault();

    const apartment = document.getElementById("apartment").value;
    const area = document.getElementById("area").value;
    const description = document.getElementById("description").value;

    fetch("http://localhost:3000/api/addRequest", {
        method: "POST",
        headers: {
            "Content-Type": "application/json",
        },
        body: JSON.stringify({
            apartment: apartment,
            area: area,
            description: description,
        }),
    })
        .then((response) => {
            if (!response.ok) {
                throw new Error("Failed to submit the request.");
            }
            return response.json();
        })
        .then((data) => {
            alert(data.message);
        })
        .catch((error) => {
            console.error("Error:", error);
            alert("An error occurred while submitting the request.");
        });
});

