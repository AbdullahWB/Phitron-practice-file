use phero;

CREATE TABLE Student (
    StudentID INT AUTO_INCREMENT PRIMARY KEY,
    Name VARCHAR(255) NOT NULL,
    Email VARCHAR(255) NOT NULL,
    Phone VARCHAR(15),
    Address TEXT
);

CREATE TABLE Book (
    ISBN VARCHAR(13) PRIMARY KEY,
    Title VARCHAR(255) NOT NULL,
    Author VARCHAR(255) NOT NULL,
    Genre VARCHAR(50),
    TotalCopies INT NOT NULL,
    AvailableCopies INT NOT NULL
);

CREATE TABLE Borrowing (
    BorrowID INT AUTO_INCREMENT PRIMARY KEY,
    StudentID INT,
    ISBN VARCHAR(13),
    BorrowDate DATE NOT NULL,
    DueDate DATE NOT NULL,
    ReturnDate DATE,
    FOREIGN KEY (StudentID) REFERENCES Student(StudentID),
    FOREIGN KEY (ISBN) REFERENCES Book(ISBN)
);


-- Step 1: Retrieve the ISBN of the book with the most available copies
SELECT ISBN
FROM Book
ORDER BY AvailableCopies DESC
LIMIT 1;

INSERT INTO Borrowing (StudentID, ISBN, BorrowDate, DueDate)
VALUES (3, 'ISBN_OF_THE_BOOK', CURDATE(), DATE_ADD(CURDATE(), INTERVAL 14 DAY));

UPDATE Book
SET AvailableCopies = AvailableCopies - 1
WHERE ISBN = '9781234567890';

SELECT S.Name
FROM Student S
JOIN (
    SELECT StudentID
    FROM Borrowing
    GROUP BY StudentID
    ORDER BY COUNT(*) DESC
    LIMIT 1
) AS MostBorrowed ON S.StudentID = MostBorrowed.StudentID;
