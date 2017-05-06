typedef struct account{
	int accountId;
	char *name;
	int balance;
}account;

typedef struct transaction{
	int transactionId;
	int accountId;
	char *date;
	int balanceChange;
	char *description;
}transaction;


