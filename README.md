Opis Projektu: Menadżer Wydatków
Menadżer Wydatków to aplikacja desktopowa napisana w języku C++ z wykorzystaniem frameworka Qt  Projekt służy do ewidencjonowania wydatków i przychodów, 
oferując użytkownikowi pełną kontrolę nad domowym budżetem poprzez przejrzysty interfejs graficzny (GUI).
Kluczowe Funkcjonalności:
Zarządzanie Transakcjami: Dodawanie, edytowanie oraz usuwanie operacji finansowych (dzięki klasom AddTransactionDialog, EditDialog oraz RemoveDialog).
Kategoryzacja: Możliwość przypisywania wydatków do konkretnych kategorii (klasa Category), co ułatwia analizę struktury wydatków.
Trwałość Danych: Wykorzystanie dedykowanej warstwy bazodanowej (DatabaseManager oraz TransactionRepository).
Architektura Techniczna:
Projekt został zaprojektowany zgodnie z dobrymi praktykami programowania obiektowego, co potwierdza obecność dokumentacji projektowej w folderze UML.
UI (User Interface): Pliki .ui zaprojektowane w Qt Designerze zapewniają oddzielenie warstwy wizualnej od logicznej.
Zarządzanie Projektem: Wykorzystanie nowoczesnego systemu budowania CMake.
Expense Manager is a desktop application developed in C++ using the Qt framework. The software is designed for tracking expenses and income, offering users full control over their household budget through a clear and intuitive Graphical User Interface (GUI).


Key Features:
Transaction Management: Add, edit, and remove financial operations using dedicated dialogs (AddTransactionDialog, EditDialog, and RemoveDialog).
Categorization: Assign expenses to specific categories (via the Category class) to facilitate detailed spending analysis.
Data Persistence: Implementation of a dedicated database layer using DatabaseManager and the Repository pattern (TransactionRepository).
Technical Architecture:
The project was designed in accordance with Object-Oriented Programming (OOP) best practices, as evidenced by the technical documentation provided in the UML folder.
UI (User Interface): .ui files designed in Qt Designer ensure a clean separation between the visual layer and the business logic (decoupling).
Project Management: Built and managed using CMake, a modern, industry-standard build system.



