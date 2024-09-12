# Banking System using c language
<h3>Overview:</h3>
The improved banking system in C is a console-based application designed to manage basic banking functions such as account creation, user login, balance checking, and money transfers. The system uses file handling to store user details securely and implements essential security features like password hashing, input validation, and error handling to enhance user experience and data integrity.

<h2>Features:</h2>
Account Creation:

Users can create an account by entering personal details such as first name, last name, Aadhaar number, phone number, and account type.
The account creation process includes validation of key information like Aadhaar and phone numbers to ensure data accuracy.
Passwords are entered using a masked input (displayed as *), and they are hashed to prevent plain-text storage, enhancing security.
User Login:

Users can securely log in to their accounts by entering a username and password.
The system checks the hashed password against stored hashed values, adding a layer of security.
Login details are validated before granting access to the system.
Money Transfer:

Users can transfer money between accounts by providing the recipient’s username and the amount to be transferred.
Basic checks are performed to ensure that the transaction is valid before proceeding.
Check Balance:

Once logged in, users can check their current account balance.
The system reads the user’s account information from a file and displays the balance.
Data Persistence:

All user data (such as personal details and hashed passwords) is stored in a file (username.txt). The system uses file handling to write, read, and update data.
This ensures that user information is persistent and available even after restarting the program.
Password Security (Hashing):

A basic password hashing mechanism is used to protect user passwords. Although a simple Caesar cipher is used for demonstration purposes in this code, the logic can be extended to use more secure libraries like OpenSSL for strong hashing algorithms such as SHA-256.
Storing hashed passwords prevents potential attackers from easily retrieving the actual passwords if the file is compromised.
Input Validation:

The system ensures that all inputs are valid before proceeding with account creation or transactions.
Aadhaar numbers are validated to be exactly 12 digits long, and phone numbers must be 10 digits, containing only numerical characters.
This reduces errors and ensures that the entered data is formatted correctly.
User Experience (UI):

The interface uses a simple text-based console system with messages that guide the user through different processes such as account creation, login, and transactions.
A small "developer credit" is displayed at the start, giving the system a personal touch.
File Error Handling:

The system handles file I/O operations with checks to prevent crashes due to missing or corrupted files. For example, if the username.txt file does not exist or cannot be opened, appropriate error messages are shown, and the program exits gracefully.
Structure:
The program is organized into separate functions that handle distinct tasks, making it modular and easier to maintain:

main Function:

This is the entry point of the system. It presents users with three options: creating an account, logging in, or exiting the program.
account Function:

Handles the account creation process. It collects user data, validates key fields (like Aadhaar and phone numbers), and prompts the user to set a password. The password is hashed before being stored.
User information is saved to the username.txt file, and the accountcreated function is called to display a confirmation message.
accountcreated Function:

Displays a message indicating that the account was successfully created. The user is then prompted to log in.
login Function:

Handles user login. It collects the username and password, hashes the entered password, and checks it against stored data to authenticate the user.
validatePhoneNumber and validateAadhaar Functions:

These functions are responsible for validating user inputs during the account creation process. The phone number must be 10 digits, and the Aadhaar number must be 12 digits. If the input is invalid, the system asks the user to re-enter the information.
hashPassword Function:

This function performs basic password hashing (using a simple Caesar cipher). In real-world applications, this should be replaced with more secure hashing algorithms from a cryptographic library like OpenSSL.
checkbalance, transfermoney, display, afterlogin, and logout Functions:

These functions (not fully detailed in the code above) handle the core functionalities of the system, such as checking the user's balance, transferring money, and logging out.
Code Walkthrough:
Account Creation:

Users enter their personal details such as name, address, Aadhaar number, and phone number. The system ensures that the phone number and Aadhaar number are correctly formatted using validation functions.
Password input is masked and hashed before being stored, ensuring that no plain-text passwords are saved in the file.
Login:

The login process checks the username and password provided by the user against the stored data. If the username exists and the hashed password matches, the user is authenticated and logged into the system.
Money Transfer:

Once logged in, users can transfer money by specifying the recipient’s username and the amount they want to transfer. The system performs basic checks to ensure the transaction is valid.
Balance Check:

Users can check their balance at any time after logging in. The system reads the balance from the stored data and displays it to the user.
Security and Validation:
Password Hashing:

Even though the program uses a basic hashing function (Caesar cipher), this demonstrates the concept of securing passwords. In a real-world implementation, stronger cryptographic methods would be used, such as SHA-256.
Input Validation:

Aadhaar numbers and phone numbers are validated to ensure they follow the correct format. This reduces errors during account creation and ensures data integrity.
Error Handling:

File operations are handled with proper error checks, ensuring that the system does not crash if files are missing or unreadable.
Future Enhancements:
Enhanced Password Hashing: Replace the simple Caesar cipher with a stronger hashing algorithm like SHA-256.
Account Balance Management: Implement a database system for better data management and real-time updates.
UI Improvements: A graphical user interface (GUI) can replace the text-based console to improve user experience.
Additional Features: Features like OTP (One-Time Password) verification for secure money transfers, detailed transaction history, and multi-factor authentication can be added for better security.
Conclusion:
This improved banking system offers a secure and user-friendly approach to managing bank accounts and transactions in a console-based environment. By incorporating features such as password hashing, input validation, and error handling, the system aims to provide a more robust and secure banking experience for its users