-- CREATE TABLES
CREATE TABLE BRANCH (
    branch_name VARCHAR(50) PRIMARY KEY,
    branch_city VARCHAR(50),
    assets INT
);

CREATE TABLE CUSTOMER (
    customer_name VARCHAR(50) PRIMARY KEY,
    customer_street VARCHAR(50),
    customer_city VARCHAR(50)
);

CREATE TABLE ACCOUNT (
    account_number INT PRIMARY KEY,
    branch_name VARCHAR(50),
    amount INT,
    FOREIGN KEY (branch_name) REFERENCES BRANCH(branch_name)
);

CREATE TABLE LOAN (
    loan_number INT PRIMARY KEY,
    branch_name VARCHAR(50),
    amount INT,
    FOREIGN KEY (branch_name) REFERENCES BRANCH(branch_name)
);

CREATE TABLE DEPOSITOR (
    customer_name VARCHAR(50),
    account_number INT,
    PRIMARY KEY (customer_name, account_number),
    FOREIGN KEY (customer_name) REFERENCES CUSTOMER(customer_name),
    FOREIGN KEY (account_number) REFERENCES ACCOUNT(account_number)
);

CREATE TABLE BORROWER (
    customer_name VARCHAR(50),
    loan_number INT,
    PRIMARY KEY (customer_name, loan_number),
    FOREIGN KEY (customer_name) REFERENCES CUSTOMER(customer_name),
    FOREIGN KEY (loan_number) REFERENCES LOAN(loan_number)
);

CREATE TABLE EMPLOYEE (
    employee_name VARCHAR(50) PRIMARY KEY,
    branch_name VARCHAR(50),
    salary INT,
    FOREIGN KEY (branch_name) REFERENCES BRANCH(branch_name)
);

-- INSERT DATA
INSERT INTO BRANCH VALUES
('Downtown', 'New York', 900000),
('Uptown', 'Brooklyn', 400000),
('Central', 'Chicago', 600000),
('Eastside', 'Boston', 300000),
('Westside', 'Dallas', 750000);

INSERT INTO CUSTOMER VALUES
('Alice', 'MG Road', 'Bangalore'),
('Bob', 'Park Street', 'Brooklyn'),
('Charlie', 'Anna Salai', 'Chicago'),
('David', 'FC Road', 'Boston'),
('Eve', 'Linking Road', 'New York');

INSERT INTO ACCOUNT VALUES
(101, 'Downtown', 400),
(102, 'Uptown', 1500),
(103, 'Central', 250),
(104, 'Eastside', 800),
(105, 'Westside', 3000);

INSERT INTO LOAN VALUES
(201, 'Downtown', 5000),
(202, 'Uptown', 3000),
(203, 'Central', 7000),
(204, 'Eastside', 2000),
(205, 'Westside', 8000);

INSERT INTO DEPOSITOR VALUES
('Alice', 101),
('Bob', 102),
('Charlie', 103),
('David', 104),
('Eve', 105);

INSERT INTO BORROWER VALUES
('Alice', 201),
('Bob', 202),
('Charlie', 203),
('David', 204),
('Eve', 205);

INSERT INTO EMPLOYEE VALUES
('John', 'Downtown', 1200),
('Jane', 'Uptown', 1600),
('Mark', 'Central', 1800),
('Sara', 'Eastside', 1400),
('Tom', 'Westside', 2000);

-- QUERIES

-- i. Customers whose balance is less than 500
SELECT C.customer_name FROM CUSTOMER C
JOIN DEPOSITOR D ON C.customer_name = D.customer_name
JOIN ACCOUNT A ON D.account_number = A.account_number
WHERE A.amount < 500;

-- ii. Employees with salary > 1400 and branch not Downtown
SELECT employee_name FROM EMPLOYEE
WHERE salary > 1400 AND branch_name != 'Downtown';

-- iii. Average salary of all employees
SELECT AVG(salary) AS Avg_Salary FROM EMPLOYEE;

-- iv. Customers whose city is not Brooklyn
SELECT customer_name FROM CUSTOMER
WHERE customer_city != 'Brooklyn';

-- v. Customers who have taken loans
SELECT DISTINCT customer_name FROM BORROWER;

-- vi. All account numbers, branch name and branch city
SELECT A.account_number, A.branch_name, B.branch_city
FROM ACCOUNT A JOIN BRANCH B ON A.branch_name = B.branch_name;

-- vii. All loan numbers sorted by branch
SELECT loan_number, branch_name FROM LOAN
ORDER BY branch_name;

-- viii. Employees who earn maximum salary
SELECT employee_name FROM EMPLOYEE
WHERE salary = (SELECT MAX(salary) FROM EMPLOYEE);