from flask import Flask, request, jsonify
import sqlite3
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

@app.route("/api/addRequest", methods=["POST"])
def add_request():
    try:
        # Get data from the request
        data = request.get_json()
        apartment = data["apartment"]
        area = data["area"]
        description = data["description"]

        # Insert data into SQLite database
        connection = sqlite3.connect("maintenance.db")
        cursor = connection.cursor()
        cursor.execute(
            "INSERT INTO requests (apartment, area, description) VALUES (?, ?, ?)",
            (apartment, area, description),
        )
        connection.commit()
        connection.close()

        return jsonify({"message": "Request submitted successfully!"})
    except Exception as e:
        return jsonify({"error": str(e)}), 500

if __name__ == "__main__":
    app.run(port=3000)


