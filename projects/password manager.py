import base64
import os

FILE = "passwords.txt"

# ----------------------------
# Encrypt (simple)
# ----------------------------
def encrypt(password):
    return base64.b64encode(password.encode()).decode()

# ----------------------------
# Decrypt
# ----------------------------
def decrypt(encoded):
    return base64.b64decode(encoded.encode()).decode()

# ----------------------------
# Add password
# ----------------------------
def add_password():
    website = input("Enter website: ")
    username = input("Enter username: ")
    password = input("Enter password: ")

    encrypted = encrypt(password)

    with open(FILE, "a") as f:
        f.write(f"{website} | {username} | {encrypted}\n")

    print("✅ Saved!\n")

# ----------------------------
# View passwords
# ----------------------------
def view_passwords():
    if not os.path.exists(FILE):
        print("No data found\n")
        return

    with open(FILE, "r") as f:
        for line in f:
            website, username, enc = line.strip().split(" | ")
            print(f"{website} | {username} | {decrypt(enc)}")

    print()

# ----------------------------
# Main menu
# ----------------------------
def main():
    while True:
        print("1. Add Password")
        print("2. View Passwords")
        print("3. Exit")

        choice = input("Enter choice: ")

        if choice == "1":
            add_password()
        elif choice == "2":
            view_passwords()
        elif choice == "3":
            break
        else:
            print("Invalid!\n")

if __name__ == "__main__":
    main()