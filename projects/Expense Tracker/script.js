// Initialize transactions from localStorage or empty array
let transactions = JSON.parse(localStorage.getItem('transactions')) || [];

const balanceEl = document.getElementById('balance');
const descEl = document.getElementById('desc');
const amountEl = document.getElementById('amount');
const typeEl = document.getElementById('type');
const addBtn = document.getElementById('add-btn');
const transactionsList = document.getElementById('transactions-list');

// Function to display transactions
function displayTransactions() {
    transactionsList.innerHTML = '';
    transactions.forEach((t, index) => {
        const li = document.createElement('li');
        li.textContent = `${t.desc} : $${t.amount} (${t.type})`;

        // Create remove button
        const removeBtn = document.createElement('button');
        removeBtn.textContent = 'Remove';
        removeBtn.addEventListener('click', () => removeTransaction(index));

        li.appendChild(removeBtn);
        transactionsList.appendChild(li);
    });
    updateBalance();
}

// Function to add a transaction
function addTransaction() {
    const desc = descEl.value.trim();
    const amount = parseFloat(amountEl.value);
    const type = typeEl.value;

    if (!desc || isNaN(amount)) {
        alert('Please enter valid description and amount');
        return;
    }

    transactions.push({ desc, amount, type });
    localStorage.setItem('transactions', JSON.stringify(transactions));

    descEl.value = '';
    amountEl.value = '';

    displayTransactions();
}

// Function to remove a transaction
function removeTransaction(index) {
    transactions.splice(index, 1);
    localStorage.setItem('transactions', JSON.stringify(transactions));
    displayTransactions();
}

// Function to calculate balance
function updateBalance() {
    let balance = 0;
    transactions.forEach(t => {
        balance += t.type === 'income' ? t.amount : -t.amount;
    });
    balanceEl.innerText = balance.toFixed(2);
}

// Event listener
addBtn.addEventListener('click', addTransaction);

// Initial display
displayTransactions();


