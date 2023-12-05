	int choice;
	cout << "Välj söktyp:\n1. Sök efter kortnummer\n2. Sök efter användarnamn\n";
    while (cin >> choice) {
        if (choice == 1) {
            int cardNumber;
            cout << "Ange kortnummer: ";
            cin >> cardNumber;
            User foundByCardNumber = validUsers.find(cardNumber);
            cout << (foundByCardNumber != UserTable::user_not_found ? "Användaren hittades." : "Användaren hittades inte.") << endl;

			cout << "\nVälj söktyp:\n1. Sök efter kortnummer\n2. Sök efter användarnamn\n";
        } else if (choice == 2) {
            string username;
            cout << "Ange användarnamn: ";
            cin >> username;
            User foundByUsername = validUsers.find(username);
            cout << (foundByUsername != UserTable::user_not_found ? "Användaren hittades.": "Användaren hittades inte.") << endl;
			
			cout << "\nVälj söktyp:\n1. Sök efter kortnummer\n2. Sök efter användarnamn\n";
        } else {
            cout << "Ogiltigt val. Välj igen:\n1. Sök efter kortnummer\n2. Sök efter användarnamn\n";
        }
    }

    cout << "Programmet avslutas. Hejdå!" << endl;

    return 0;
