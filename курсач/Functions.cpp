#include "Data.h"


//Розрахунок суми виручки
void branchProfitFromOrdersСalc(const Orders& orders, Revenue& revenue, int branchNumber)
{
	float pricePerPhoto10x15, pricePerPhoto15x21, pricePerPhoto21x30, pricePerPhoto30x45, pricePerFilm,
		pricePerPrint = 0, pricePerDevelop = 0,
		pricePerPrintExpress = 0, pricePerDevelopExpress = 0, pricePerCombinedExpress = 0,
		revenueFromPrint = 0, revenueFromDevelop = 0, revenueFromCombined = 0,
		revenueFromPrintExpress = 0, revenueFromDevelopExpress = 0, revenueFromCombinedExpress = 0;

	const vector<OrderForPrint>& OrdersForPrint = orders.getOrdersForPrint();
	const vector<OrderForDevelopment>& OrdersForDevelopment = orders.getOrdersForDevelopment();
	const vector<CombinedOrder>& CombinedOrders = orders.getCombinedOrders();

	//Виручка за друк
	for (const OrderForPrint& OrderForPrint : OrdersForPrint) {
		if (OrderForPrint.getBranch() == branchNumber) {
			if (OrderForPrint.getFormat() == "10x15") {
				if (OrderForPrint.getNumPhotos() < 100) {
					pricePerPhoto10x15 = 5.4;
					pricePerPrint = OrderForPrint.getNumPhotos() * pricePerPhoto10x15;
				}
				else if (OrderForPrint.getNumPhotos() > 100) {
					pricePerPhoto10x15 = 4.7;
					pricePerPrint = OrderForPrint.getNumPhotos() * pricePerPhoto10x15;
				}
				else if (OrderForPrint.getNumPhotos() > 200) {
					pricePerPhoto10x15 = 4.4;
					pricePerPrint = OrderForPrint.getNumPhotos() * pricePerPhoto10x15;
				}
			}
			else if (OrderForPrint.getFormat() == "15x21") {
				if (OrderForPrint.getNumPhotos() < 100) {
					pricePerPhoto15x21 = 10.8;
					pricePerPrint = OrderForPrint.getNumPhotos() * pricePerPhoto15x21;
				}
				else if (OrderForPrint.getNumPhotos() > 100) {
					pricePerPhoto15x21 = 9.8;
					pricePerPrint = OrderForPrint.getNumPhotos() * pricePerPhoto15x21;
				}
				else if (OrderForPrint.getNumPhotos() > 200) {
					pricePerPhoto15x21 = 9.3;
					pricePerPrint = OrderForPrint.getNumPhotos() * pricePerPhoto15x21;
				}
			}
			else if (OrderForPrint.getFormat() == "21x30")
			{
				if (OrderForPrint.getNumPhotos() < 100) {
					pricePerPhoto21x30 = 20.8;
					pricePerPrint = OrderForPrint.getNumPhotos() * pricePerPhoto21x30;
				}
				else if (OrderForPrint.getNumPhotos() > 100) {
					pricePerPhoto21x30 = 18.8;
					pricePerPrint = OrderForPrint.getNumPhotos() * pricePerPhoto21x30;
				}
				else if (OrderForPrint.getNumPhotos() > 200) {
					pricePerPhoto21x30 = 17.8;
					pricePerPrint = OrderForPrint.getNumPhotos() * pricePerPhoto21x30;
				}
			}
			else if (OrderForPrint.getFormat() == "30x45")
			{
				if (OrderForPrint.getNumPhotos() < 100) {
					pricePerPhoto30x45 = 55;
					pricePerPrint = OrderForPrint.getNumPhotos() * pricePerPhoto30x45;
				}
				else if (OrderForPrint.getNumPhotos() > 100) {
					pricePerPhoto30x45 = 49;
					pricePerPrint = OrderForPrint.getNumPhotos() * pricePerPhoto30x45;
				}
				else if (OrderForPrint.getNumPhotos() > 200) {
					pricePerPhoto30x45 = 47;
					pricePerPrint = OrderForPrint.getNumPhotos() * pricePerPhoto30x45;
				}
			}
			
			if (OrderForPrint.getExpress()) {
				pricePerPrintExpress = pricePerPrint * 2;
				revenueFromPrintExpress = revenueFromPrintExpress + pricePerPrintExpress;
			}
			else
			{
				revenueFromPrint = revenueFromPrint + pricePerPrint;
			}
		}
	}
//Виручка за проявлення
	for (const OrderForDevelopment& OrderForDevelopment : OrdersForDevelopment) {
		if (OrderForDevelopment.getBranch() == branchNumber) {
			if (!OrderForDevelopment.getBoughtHere()) {
				pricePerFilm = 150;
				pricePerDevelop = OrderForDevelopment.getNumFilms() * pricePerFilm;
				
				if (OrderForDevelopment.getExpress()) {
					pricePerDevelopExpress = pricePerDevelop * 2;
					revenueFromDevelopExpress = revenueFromDevelopExpress + pricePerDevelopExpress;
				}
				else
				{
					revenueFromDevelop = revenueFromDevelop + pricePerDevelop;
				}
			}
		}
	}
//Виручка за друк і проявлення
	for (const CombinedOrder& CombinedOrder : CombinedOrders) {
		if (CombinedOrder.getBranch() == branchNumber) {
			if (CombinedOrder.getFormat() == "10x15") {
				if (CombinedOrder.getNumPhotos() < 100) {
					pricePerPhoto10x15 = 5.4;
					pricePerPrint = CombinedOrder.getNumPhotos() * pricePerPhoto10x15;
				}
				else if (CombinedOrder.getNumPhotos() > 100) {
					pricePerPhoto10x15 = 4.7;
					pricePerPrint = CombinedOrder.getNumPhotos() * pricePerPhoto10x15;
				}
				else if (CombinedOrder.getNumPhotos() > 200) {
					pricePerPhoto10x15 = 4.4;
					pricePerPrint = CombinedOrder.getNumPhotos() * pricePerPhoto10x15;
				}
			}
			else if (CombinedOrder.getFormat() == "15x21") {
				if (CombinedOrder.getNumPhotos() < 100) {
					pricePerPhoto15x21 = 10.8;
					pricePerPrint = CombinedOrder.getNumPhotos() * pricePerPhoto15x21;
				}
				else if (CombinedOrder.getNumPhotos() > 100) {
					pricePerPhoto15x21 = 9.8;
					pricePerPrint = CombinedOrder.getNumPhotos() * pricePerPhoto15x21;
				}
				else if (CombinedOrder.getNumPhotos() > 200) {
					pricePerPhoto15x21 = 9.3;
					pricePerPrint = CombinedOrder.getNumPhotos() * pricePerPhoto15x21;
				}
			}
			else if (CombinedOrder.getFormat() == "21x30")
			{
				if (CombinedOrder.getNumPhotos() < 100) {
					pricePerPhoto21x30 = 20.8;
					pricePerPrint = CombinedOrder.getNumPhotos() * pricePerPhoto21x30;
				}
				else if (CombinedOrder.getNumPhotos() > 100) {
					pricePerPhoto21x30 = 18.8;
					pricePerPrint = CombinedOrder.getNumPhotos() * pricePerPhoto21x30;
				}
				else if (CombinedOrder.getNumPhotos() > 200) {
					pricePerPhoto21x30 = 17.8;
					pricePerPrint = CombinedOrder.getNumPhotos() * pricePerPhoto21x30;
				}
			}
			else if (CombinedOrder.getFormat() == "30x45")
			{
				if (CombinedOrder.getNumPhotos() < 100) {
					pricePerPhoto30x45 = 55;
					pricePerPrint = CombinedOrder.getNumPhotos() * pricePerPhoto30x45;
				}
				else if (CombinedOrder.getNumPhotos() > 100) {
					pricePerPhoto30x45 = 49;
					pricePerPrint = CombinedOrder.getNumPhotos() * pricePerPhoto30x45;
				}
				else if (CombinedOrder.getNumPhotos() > 200) {
					pricePerPhoto30x45 = 47;
					pricePerPrint = CombinedOrder.getNumPhotos() * pricePerPhoto30x45;
				}
			}
			
			pricePerFilm = 150;
			pricePerDevelop = CombinedOrder.getNumFilms() * pricePerFilm;
			
			if (CombinedOrder.getExpress()) {
				pricePerCombinedExpress = (pricePerPrint + pricePerDevelop) * 2;
				revenueFromCombinedExpress = revenueFromCombinedExpress + pricePerCombinedExpress;
			}
			else
			{
				revenueFromCombined = revenueFromCombined + pricePerPrint + pricePerDevelop;
			}
		}
	}

	RevenueFromExpressOrders revenueFromExpressOrders(revenueFromPrint, revenueFromDevelop, revenueFromCombined, revenueFromPrintExpress, revenueFromDevelopExpress, revenueFromCombinedExpress);
	
	revenue.addRevenueFromExpressOrders(revenueFromExpressOrders);
}
void kioskProfitFromOrdersСalc(const Orders& orders, Revenue& revenue, int kioskNumber)
{
	float pricePerPhoto10x15, pricePerPhoto15x21, pricePerPhoto21x30, pricePerPhoto30x45, pricePerFilm,
		pricePerPrint = 0, pricePerDevelop = 0,
		revenueFromPrint = 0, revenueFromDevelop = 0, revenueFromCombined = 0;

	const vector<OrderForPrint>& OrdersForPrint = orders.getOrdersForPrint();
	const vector<OrderForDevelopment>& OrdersForDevelopment = orders.getOrdersForDevelopment();
	const vector<CombinedOrder>& CombinedOrders = orders.getCombinedOrders();

	//Виручка за друк
	for (const OrderForPrint& OrderForPrint : OrdersForPrint) {
		if (OrderForPrint.getKiosk() == kioskNumber) {
			if (OrderForPrint.getFormat() == "10x15") {
				if (OrderForPrint.getNumPhotos() < 100) {
					pricePerPhoto10x15 = 5.4;
					pricePerPrint = OrderForPrint.getNumPhotos() * pricePerPhoto10x15;
				}
				else if (OrderForPrint.getNumPhotos() > 100) {
					pricePerPhoto10x15 = 4.7;
					pricePerPrint = OrderForPrint.getNumPhotos() * pricePerPhoto10x15;
				}
				else if (OrderForPrint.getNumPhotos() > 200) {
					pricePerPhoto10x15 = 4.4;
					pricePerPrint = OrderForPrint.getNumPhotos() * pricePerPhoto10x15;
				}
			}
			else if (OrderForPrint.getFormat() == "15x21") {
				if (OrderForPrint.getNumPhotos() < 100) {
					pricePerPhoto15x21 = 10.8;
					pricePerPrint = OrderForPrint.getNumPhotos() * pricePerPhoto15x21;
				}
				else if (OrderForPrint.getNumPhotos() > 100) {
					pricePerPhoto15x21 = 9.8;
					pricePerPrint = OrderForPrint.getNumPhotos() * pricePerPhoto15x21;
				}
				else if (OrderForPrint.getNumPhotos() > 200) {
					pricePerPhoto15x21 = 9.3;
					pricePerPrint = OrderForPrint.getNumPhotos() * pricePerPhoto15x21;
				}
			}
			else if (OrderForPrint.getFormat() == "21x30")
			{
				if (OrderForPrint.getNumPhotos() < 100) {
					pricePerPhoto21x30 = 20.8;
					pricePerPrint = OrderForPrint.getNumPhotos() * pricePerPhoto21x30;
				}
				else if (OrderForPrint.getNumPhotos() > 100) {
					pricePerPhoto21x30 = 18.8;
					pricePerPrint = OrderForPrint.getNumPhotos() * pricePerPhoto21x30;
				}
				else if (OrderForPrint.getNumPhotos() > 200) {
					pricePerPhoto21x30 = 17.8;
					pricePerPrint = OrderForPrint.getNumPhotos() * pricePerPhoto21x30;
				}
			}
			else if (OrderForPrint.getFormat() == "30x45")
			{
				if (OrderForPrint.getNumPhotos() < 100) {
					pricePerPhoto30x45 = 55;
					pricePerPrint = OrderForPrint.getNumPhotos() * pricePerPhoto30x45;
				}
				else if (OrderForPrint.getNumPhotos() > 100) {
					pricePerPhoto30x45 = 49;
					pricePerPrint = OrderForPrint.getNumPhotos() * pricePerPhoto30x45;
				}
				else if (OrderForPrint.getNumPhotos() > 200) {
					pricePerPhoto30x45 = 47;
					pricePerPrint = OrderForPrint.getNumPhotos() * pricePerPhoto30x45;
				}
			}
			revenueFromPrint = revenueFromPrint + pricePerPrint;
		}
	}
	//Виручка за проявлення
	for (const OrderForDevelopment& OrderForDevelopment : OrdersForDevelopment) {
		if (OrderForDevelopment.getKiosk() == kioskNumber) {
			if (!OrderForDevelopment.getBoughtHere()) {
				pricePerFilm = 150;
				pricePerDevelop = OrderForDevelopment.getNumFilms() * pricePerFilm;

				revenueFromDevelop = revenueFromDevelop + pricePerDevelop;
			}
		}
	}

	//Виручка за друк і проявлення
	for (const CombinedOrder& CombinedOrder : CombinedOrders) {
		if (CombinedOrder.getKiosk() == kioskNumber) {
			if (CombinedOrder.getFormat() == "10x15") {
				if (CombinedOrder.getNumPhotos() < 100) {
					pricePerPhoto10x15 = 5.4;
					pricePerPrint = CombinedOrder.getNumPhotos() * pricePerPhoto10x15;
				}
				else if (CombinedOrder.getNumPhotos() > 100) {
					pricePerPhoto10x15 = 4.7;
					pricePerPrint = CombinedOrder.getNumPhotos() * pricePerPhoto10x15;
				}
				else if (CombinedOrder.getNumPhotos() > 200) {
					pricePerPhoto10x15 = 4.4;
					pricePerPrint = CombinedOrder.getNumPhotos() * pricePerPhoto10x15;
				}
			}
			else if (CombinedOrder.getFormat() == "15x21") {
				if (CombinedOrder.getNumPhotos() < 100) {
					pricePerPhoto15x21 = 10.8;
					pricePerPrint = CombinedOrder.getNumPhotos() * pricePerPhoto15x21;
				}
				else if (CombinedOrder.getNumPhotos() > 100) {
					pricePerPhoto15x21 = 9.8;
					pricePerPrint = CombinedOrder.getNumPhotos() * pricePerPhoto15x21;
				}
				else if (CombinedOrder.getNumPhotos() > 200) {
					pricePerPhoto15x21 = 9.3;
					pricePerPrint = CombinedOrder.getNumPhotos() * pricePerPhoto15x21;
				}
			}
			else if (CombinedOrder.getFormat() == "21x30")
			{
				if (CombinedOrder.getNumPhotos() < 100) {
					pricePerPhoto21x30 = 20.8;
					pricePerPrint = CombinedOrder.getNumPhotos() * pricePerPhoto21x30;
				}
				else if (CombinedOrder.getNumPhotos() > 100) {
					pricePerPhoto21x30 = 18.8;
					pricePerPrint = CombinedOrder.getNumPhotos() * pricePerPhoto21x30;
				}
				else if (CombinedOrder.getNumPhotos() > 200) {
					pricePerPhoto21x30 = 17.8;
					pricePerPrint = CombinedOrder.getNumPhotos() * pricePerPhoto21x30;
				}
			}
			else if (CombinedOrder.getFormat() == "30x45")
			{
				if (CombinedOrder.getNumPhotos() < 100) {
					pricePerPhoto30x45 = 55;
					pricePerPrint = CombinedOrder.getNumPhotos() * pricePerPhoto30x45;
				}
				else if (CombinedOrder.getNumPhotos() > 100) {
					pricePerPhoto30x45 = 49;
					pricePerPrint = CombinedOrder.getNumPhotos() * pricePerPhoto30x45;
				}
				else if (CombinedOrder.getNumPhotos() > 200) {
					pricePerPhoto30x45 = 47;
					pricePerPrint = CombinedOrder.getNumPhotos() * pricePerPhoto30x45;
				}
			}

			pricePerFilm = 150;
			pricePerDevelop = CombinedOrder.getNumFilms() * pricePerFilm;

			revenueFromCombined = revenueFromCombined + pricePerPrint + pricePerDevelop;
		}
	}

	RevenueFromSimpleOrders revenueFromSimpleOrders(revenueFromPrint, revenueFromDevelop, revenueFromCombined);

	revenue.addRevenueFromSimpleOrders(revenueFromSimpleOrders);
}

//Перелік філій та кіосків
void printBranchesAndKiosks(const PhotoCenter& photoCenter)
{
	const vector<Branch>& branches = photoCenter.getBranches();
	const vector<Kiosk>& kiosks = photoCenter.getKiosks();

	cout << "------------------------------------------------------------------------\n";
	cout << "Філії:" << endl;
	cout << "------------------------------------------------------------------------\n";
	for (const Branch& branch : branches) {
		cout << "Філія №" << branch.getBranchNum() << endl;
		cout << "Адреса: " << branch.getAddress() << endl;
		cout << endl;
		cout << "------------------------------------------------------------------------\n";
		cout << "Кіоски, прикріплені до філії №" << branch.getBranchNum() << ":" << endl;
		for (const Kiosk& kiosk : kiosks) {
			if (kiosk.getAttachedBranch() == branch.getBranchNum()) {
				cout << "\nКіоск №" << kiosk.getKioskNum() << endl;
				cout << "Адреса: " << kiosk.getAddress() << endl;
				cout << endl;
			}
		}
		cout << "------------------------------------------------------------------------\n------------------------------------------------------------------------\n";
	}
}

//Перелік всіх замовлень
void printOrders(const Orders& orders)
{
	int nb = 0, nk = 0, i;
	const vector<OrderForPrint>& OrdersForPrint = orders.getOrdersForPrint();
	const vector<OrderForDevelopment>& OrdersForDevelopment = orders.getOrdersForDevelopment();
	const vector<CombinedOrder>& CombinedOrders = orders.getCombinedOrders();
	
	cout << "------------------------------------------------------------------------\n";
	cout << "Перелік замовлень по філіям за тиждень:" << endl;
	cout << "------------------------------------------------------------------------\n";
	cout << "На друк фотографій:\n";
	i = 1;
	for (const OrderForPrint& OrderForPrint : OrdersForPrint) {
		if (OrderForPrint.getBranch() != NULL)
		{
			cout << "\nЗамовлення №" << i << endl
				<< "Кількість фото з кожного кадру: " << OrderForPrint.getNumPhotosPF() << ";  (Загальна кількість фото: " << OrderForPrint.getNumPhotos() << ")" << endl
				<< "Тип паперу: " << OrderForPrint.getPaperType() << ";  Формат: " << OrderForPrint.getFormat() << endl;
			cout << "Тип замовлення: ";
			if (OrderForPrint.getExpress()) {
				cout << "Термінове" << endl;
			}
			else {
				cout << "Просте" << endl;
			}
			i++;
			nb = nb + 1;
		}
	}
	
	cout << "------------------------------------------------------------------------\n";
	cout << "На проявлення фотоплівок:\n";
	i = 1;
	for (const OrderForDevelopment& OrderForDevelopment : OrdersForDevelopment) {
		if (OrderForDevelopment.getBranch() != NULL)
		{
			cout << "\nЗамовлення №" << i << endl
				<< "Кількість плівок для проявлення: " << OrderForDevelopment.getNumFilms() << endl;
			cout << "Тип замовлення: ";
			if (OrderForDevelopment.getExpress()) {
				cout << "Термінове" << endl;
			}
			else {
				cout << "Просте" << endl;
			}
			i++;
			nb = nb + 1;
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "На друк та проявлення разом:\n";
	i = 1;
	for (const CombinedOrder& CombinedOrder : CombinedOrders) {
		if (CombinedOrder.getBranch() != NULL)
		{
			cout << "\nЗамовлення №" << i << endl
				<< "Кількість фото з кожного кадру: " << CombinedOrder.getNumPhotosPF() << ";  (Загальна кількість фото: " << CombinedOrder.getNumPhotos() << ")" << endl
				<< "Тип паперу: " << CombinedOrder.getPaperType() << ";  Формат: " << CombinedOrder.getFormat() << endl
				<< "Кількість плівок для проявлення: " << CombinedOrder.getNumFilms() << endl;
			cout << "Тип замовлення: ";
			if (CombinedOrder.getExpress()) {
				cout << "Термінове" << endl;
			}
			else {
				cout << "Просте" << endl;
			}
			i++;
			nb = nb + 1;
		}
	}
	cout << "------------------------------------------------------------------------\n";
	
	cout << "Перелік замовлень по кіоскам за тиждень:" << endl;
	cout << "------------------------------------------------------------------------\n";
	cout << "На друк фотографій:\n";
	i = 1;
	for (const OrderForPrint& OrderForPrint : OrdersForPrint) {
		if (OrderForPrint.getKiosk() != NULL)
		{
			cout << "\nЗамовлення №" << i << endl
				<< "Кількість фото з кожного кадру: " << OrderForPrint.getNumPhotosPF() << ";  (Загальна кількість фото: " << OrderForPrint.getNumPhotos() << ")" << endl
				<< "Тип паперу: " << OrderForPrint.getPaperType() << ";  Формат: " << OrderForPrint.getFormat() << endl;
			cout << "Тип замовлення: Просте" << endl;
			i++;
			nk = nk + 1;
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "На проявлення фотоплівок:\n";
	i = 1;
	for (const OrderForDevelopment& OrderForDevelopment : OrdersForDevelopment) {
		if (OrderForDevelopment.getKiosk() != NULL)
		{
			cout << "\nЗамовлення №" << i << endl
				<< "Кількість плівок для проявлення: " << OrderForDevelopment.getNumFilms() << endl;
			cout << "Тип замовлення: Просте" << endl;
			i++;
			nk = nk + 1;
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "На друк та проявлення разом:\n";
	i = 1;
	for (const CombinedOrder& CombinedOrder : CombinedOrders) {
		if (CombinedOrder.getKiosk() != NULL)
		{
			cout << "\nЗамовлення №" << i << endl
				<< "Кількість фото з кожного кадру: " << CombinedOrder.getNumPhotosPF() << ";  (Загальна кількість фото: " << CombinedOrder.getNumPhotos() << ")" << endl
				<< "Тип паперу: " << CombinedOrder.getPaperType() << ";  Формат: " << CombinedOrder.getFormat() << endl
				<< "Кількість плівок для проявлення: " << CombinedOrder.getNumFilms() << endl;
			cout << "Тип замовлення: Просте" << endl;
			i++;
			nk = nk + 1;
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "Загальна кількість замовлень по філіям за тиждень: " << nb << endl;
	cout << "------------------------------------------------------------------------\n";
	cout << "Загальна кількість замовлень по кіоскам за тиждень: " << nk << endl;
	cout << "------------------------------------------------------------------------\n";
	cout << "Загальна кількість замовлень по фото центру за тиждень: " << nb + nk << endl;
}

//Перелік всіх замовлень (окремо простих та термінових)
void printOrdersForBranchByNumber(const Orders& orders, int branchNumber) 
{
	int nb = 0, nbe = 0, i;
	
	const vector<OrderForPrint>& OrdersForPrint = orders.getOrdersForPrint();
	const vector<OrderForDevelopment>& OrdersForDevelopment = orders.getOrdersForDevelopment();
	const vector<CombinedOrder>& CombinedOrders = orders.getCombinedOrders();

	cout << "------------------------------------------------------------------------\n";
	cout << "Звіт філії №" << branchNumber << endl;
	cout << "------------------------------------------------------------------------\n";
	cout << "Перелік простих замовлень за тиждень:" << endl;

	cout << "------------------------------------------------------------------------\n";
	cout << "На друк фотографій:\n";
	i = 1;
	for (const OrderForPrint& OrderForPrint : OrdersForPrint) {
		if (OrderForPrint.getBranch() == branchNumber && !OrderForPrint.getExpress()) {
			cout << "\nЗамовлення №" << i << endl
				<< "Кількість фото з кожного кадру: " << OrderForPrint.getNumPhotosPF() << " |	Загальна кількість фото: " << OrderForPrint.getNumPhotos() << endl
				<< "Тип паперу: " << OrderForPrint.getPaperType() << " |  Формат: " << OrderForPrint.getFormat() << endl;
			i++;
			nb = nb + 1;
		}
	}

	cout << "\n------------------------------------------------------------------------\n";
	cout << "На проявлення фотоплівок:\n";
	i = 1;
	for (const OrderForDevelopment& OrderForDevelopment : OrdersForDevelopment) {
		if (OrderForDevelopment.getBranch() == branchNumber && !OrderForDevelopment.getExpress()) {
			cout << "\nЗамовлення №" << i << endl
				<< "Кількість плівок для проявлення: " << OrderForDevelopment.getNumFilms() << endl;
			i++;
			nb = nb + 1;
		}
	}

	cout << "\n------------------------------------------------------------------------\n";
	cout << "На друк та проявлення разом:\n";
	i = 1;
	for (const CombinedOrder& CombinedOrder : CombinedOrders) {
		if (CombinedOrder.getBranch() == branchNumber && !CombinedOrder.getExpress()) {
			cout << "\nЗамовлення №" << i << endl
				<< "Кількість фото з кожного кадру: " << CombinedOrder.getNumPhotosPF() << " |	Загальна кількість фото: " << CombinedOrder.getNumPhotos() << endl
				<< "Тип паперу: " << CombinedOrder.getPaperType() << " |  Формат: " << CombinedOrder.getFormat() << endl
				<< "Кількість плівок для проявлення: " << CombinedOrder.getNumFilms() << endl;
			i++;
			nb = nb + 1;
		}
	}

	cout << "\n------------------------------------------------------------------------\n";
	cout << "Перелік термінових замовлень для філії №" << branchNumber << " за тиждень:" << endl;

	cout << "------------------------------------------------------------------------\n";
	cout << "На друк фотографій:\n";
	i = 1;
	for (const OrderForPrint& OrderForPrint : OrdersForPrint) {
		if (OrderForPrint.getBranch() == branchNumber && OrderForPrint.getExpress()) {
			cout << "\nЗамовлення №" << i << endl
				<< "Кількість фото з кожного кадру: " << OrderForPrint.getNumPhotosPF() << " |	Загальна кількість фото: " << OrderForPrint.getNumPhotos() << endl
				<< "Тип паперу: " << OrderForPrint.getPaperType() << " |  Формат: " << OrderForPrint.getFormat() << endl;
			i++;
			nbe = nbe + 1;
		}
	}

	cout << "\n------------------------------------------------------------------------\n";
	cout << "На проявлення фотоплівок:\n";
	i = 1;
	for (const OrderForDevelopment& OrderForDevelopment : OrdersForDevelopment) {
		if (OrderForDevelopment.getBranch() == branchNumber && OrderForDevelopment.getExpress()) {
			cout << "\nЗамовлення №" << i << endl
				<< "Кількість плівок для проявлення: " << OrderForDevelopment.getNumFilms() << endl;
			i++;
			nbe = nbe + 1;
		}
	}

	cout << "\n------------------------------------------------------------------------\n";
	cout << "На друк та проявлення разом:\n";
	i = 1;
	for (const CombinedOrder& CombinedOrder : CombinedOrders) {
		if (CombinedOrder.getBranch() == branchNumber && CombinedOrder.getExpress()) {
			cout << "\nЗамовлення №" << i << endl
				<< "Кількість фото з кожного кадру: " << CombinedOrder.getNumPhotosPF() << " |	Загальна кількість фото: " << CombinedOrder.getNumPhotos() << endl
				<< "Тип паперу: " << CombinedOrder.getPaperType() << " |  Формат: " << CombinedOrder.getFormat() << endl
				<< "Кількість плівок для проявлення: " << CombinedOrder.getNumFilms() << endl;
			i++;
			nbe = nbe + 1;
		}
	}

	cout << "\n------------------------------------------------------------------------\n";
	cout << "Загальна кількість простих замовлень для вказаної філії за тиждень: " << nb << endl;
	cout << "------------------------------------------------------------------------\n";
	cout << "Загальна кількість термінових замовлень для вказаної філії за тиждень: " << nbe << endl;
	cout << "------------------------------------------------------------------------\n";
}
void printOrdersForKioskByNumber(const Orders& orders, int kioskNumber)
{
	int nk = 0, i;

	const vector<OrderForPrint>& OrdersForPrint = orders.getOrdersForPrint();
	const vector<OrderForDevelopment>& OrdersForDevelopment = orders.getOrdersForDevelopment();
	const vector<CombinedOrder>& CombinedOrders = orders.getCombinedOrders();

	cout << "------------------------------------------------------------------------\n";
	cout << "Звіт кіоску №" << kioskNumber << endl;
	cout << "------------------------------------------------------------------------\n";
	cout << "Перелік простих замовлень за тиждень:" << endl;

	cout << "------------------------------------------------------------------------\n";
	cout << "На друк фотографій:\n";
	i = 1;
	for (const OrderForPrint& OrderForPrint : OrdersForPrint) {
		if (OrderForPrint.getKiosk() == kioskNumber) {
			cout << "\nЗамовлення №" << i << endl
				<< "Кількість фото з кожного кадру: " << OrderForPrint.getNumPhotosPF() << " |	Загальна кількість фото: " << OrderForPrint.getNumPhotos() << endl
				<< "Тип паперу: " << OrderForPrint.getPaperType() << " |  Формат: " << OrderForPrint.getFormat() << endl;
			i++;
			nk = nk + 1;
		}
	}

	cout << "\n------------------------------------------------------------------------\n";
	cout << "На проявлення фотоплівок:\n";
	i = 1;
	for (const OrderForDevelopment& OrderForDevelopment : OrdersForDevelopment) {
		if (OrderForDevelopment.getKiosk() == kioskNumber) {
			cout << "\nЗамовлення №" << i << endl
				<< "Кількість плівок для проявлення: " << OrderForDevelopment.getNumFilms() << endl;
			i++;
			nk = nk + 1;
		}
	}

	cout << "\n------------------------------------------------------------------------\n";
	cout << "На друк та проявлення разом:\n";
	i = 1;
	for (const CombinedOrder& CombinedOrder : CombinedOrders) {
		if (CombinedOrder.getKiosk() == kioskNumber) {
			cout << "\nЗамовлення №" << i << endl
				<< "Кількість фото з кожного кадру: " << CombinedOrder.getNumPhotosPF() << " |	Загальна кількість фото: " << CombinedOrder.getNumPhotos() << endl
				<< "Тип паперу: " << CombinedOrder.getPaperType() << " |  Формат: " << CombinedOrder.getFormat() << endl
				<< "Кількість плівок для проявлення: " << CombinedOrder.getNumFilms() << endl;
			i++;
			nk = nk + 1;
		}
	}

	cout << "\n------------------------------------------------------------------------\n";
	cout << "Загальна кількість простих замовлень для вказаного кіоску за тиждень: " << nk << endl;
}

//Вивід суми виручки 
void printBranchProfitFromOrders(const Orders& orders, const Revenue& revenue, int branchNumber)
{
	const vector<OrderForPrint>& OrdersForPrint = orders.getOrdersForPrint();
	const vector<OrderForDevelopment>& OrdersForDevelopment = orders.getOrdersForDevelopment();
	const vector<CombinedOrder>& CombinedOrders = orders.getCombinedOrders();
	const vector<RevenueFromExpressOrders>& RevenueFromExpressOrders_ = revenue.getRevenueFromExpressOrders_();

	for (const RevenueFromExpressOrders& RevenueFromExpressOrders : RevenueFromExpressOrders_) {
		cout << "------------------------------------------------------------------------\n";
		cout << "Звіт філії №" << branchNumber << endl << endl;
		cout << "Сума виручки із простих замовлень за тиждень:" << endl;
		cout << "------------------------------------------------------------------------\n";
		cout << "З замовлень на друк фотографій: " << RevenueFromExpressOrders.getRevenueFromPrint() << " грн." << endl << endl;
		cout << "З замовлень на проявлення фотоплівок: " << RevenueFromExpressOrders.getRevenueFromDevelop() << " грн." << endl << endl;
		cout << "З замовлень на друк і проявлення разом: " << RevenueFromExpressOrders.getRevenueFromCombined() << " грн." << endl;

		cout << "------------------------------------------------------------------------\n";
		cout << "Сума виручки із термінових замовлень за тиждень:" << endl;
		cout << "------------------------------------------------------------------------\n";
		cout << "З замовлень на друк фотографій: " << RevenueFromExpressOrders.getRevenueFromPrintExpress() << " грн." << endl << endl;
		cout << "З замовлень на проявлення фотоплівок: " << RevenueFromExpressOrders.getRevenueFromDevelopExpress() << " грн." << endl << endl;
		cout << "З замовлень на друк і проявлення разом: " << RevenueFromExpressOrders.getRevenueFromCombinedExpress() << " грн." << endl;
	}
}
void printKioskProfitFromOrders(const Orders& orders, const Revenue& revenue, int kioskNumber)
{
	const vector<OrderForPrint>& OrdersForPrint = orders.getOrdersForPrint();
	const vector<OrderForDevelopment>& OrdersForDevelopment = orders.getOrdersForDevelopment();
	const vector<CombinedOrder>& CombinedOrders = orders.getCombinedOrders();
	const vector<RevenueFromSimpleOrders>& RevenueFromSimpleOrders_ = revenue.getRevenueFromSimpleOrders_();

	for (const RevenueFromSimpleOrders& RevenueFromSimpleOrders : RevenueFromSimpleOrders_) {
		cout << "------------------------------------------------------------------------\n";
		cout << "Звіт кіоску №" << kioskNumber << endl << endl;
		cout << "Сума виручки за тиждень:" << endl;
		cout << "------------------------------------------------------------------------\n";
		cout << "З замовлень на друк фотографій: " << RevenueFromSimpleOrders.getRevenueFromPrint() << " грн." << endl << endl;
		cout << "З замовлень на проявлення фотоплівок: " << RevenueFromSimpleOrders.getRevenueFromDevelop() << " грн." << endl << endl;
		cout << "З замовлень на друк і проявлення разом: " << RevenueFromSimpleOrders.getRevenueFromCombined() << " грн." << endl;
	}
}

//Вивід кількості надрукованих фотографій
void printBranchNumOfPhotos(const Orders& orders, int branchNumber)
{
	const vector<OrderForPrint>& OrdersForPrint = orders.getOrdersForPrint();
	const vector<CombinedOrder>& CombinedOrders = orders.getCombinedOrders();

	int ns = 0, ne = 0;

	cout << "------------------------------------------------------------------------\n";
	cout << "Звіт філії №" << branchNumber << endl << endl;
	cout << "Кількість надрукованих фотографій за тиждень:" << endl << endl;
	for (const OrderForPrint& OrderForPrint : OrdersForPrint) {
		if (OrderForPrint.getBranch() == branchNumber && !OrderForPrint.getExpress()) {
			ns = ns + OrderForPrint.getNumPhotos();
		}
		else if (OrderForPrint.getBranch() == branchNumber && OrderForPrint.getExpress()) {
			ne = ne + OrderForPrint.getNumPhotos();
		}
	}
	for (const CombinedOrder& CombinedOrder : CombinedOrders) {
		if (CombinedOrder.getBranch() == branchNumber && !CombinedOrder.getExpress()) {
			ns = ns + CombinedOrder.getNumPhotos();
		}
		else if (CombinedOrder.getBranch() == branchNumber && CombinedOrder.getExpress()) {
			ne = ne + CombinedOrder.getNumPhotos();
		}
	}
	cout << "З простих замовлень: "<< ns << endl;
	cout << "З термінових замовлень: " << ne << endl;
	cout << "Загалом: " << ns + ne << endl;
	
}
void printKioskNumOfPhotos(const Orders& orders, int kioskNumber)
{
	const vector<OrderForPrint>& OrdersForPrint = orders.getOrdersForPrint();
	const vector<CombinedOrder>& CombinedOrders = orders.getCombinedOrders();

	int ns = 0;

	cout << "------------------------------------------------------------------------\n";
	cout << "Звіт кіоску №" << kioskNumber << endl << endl;
	cout << "Кількість надрукованих фотографій за тиждень:" << endl << endl;
	for (const OrderForPrint& OrderForPrint : OrdersForPrint) {
		if (OrderForPrint.getKiosk() == kioskNumber && !OrderForPrint.getExpress()) {
			ns = ns + OrderForPrint.getNumPhotos();
		}
	}
	for (const CombinedOrder& CombinedOrder : CombinedOrders) {
		if (CombinedOrder.getKiosk() == kioskNumber && !CombinedOrder.getExpress()) {
			ns = ns + CombinedOrder.getNumPhotos();
		}
	}
	cout << "З простих замовлень: " << ns << endl;
}

//Вивід кількості проявлених фотоплівок
void printBranchNumOfFilms(const Orders& orders, int branchNumber)
{
	const vector<OrderForDevelopment>& OrdersForDevelopment = orders.getOrdersForDevelopment();
	const vector<CombinedOrder>& CombinedOrders = orders.getCombinedOrders();

	int ns = 0, ne = 0;

	cout << "------------------------------------------------------------------------\n";
	cout << "Звіт філії №" << branchNumber << endl << endl;
	cout << "Кількість проявлених фотоплівок за тиждень:" << endl << endl;
	for (const OrderForDevelopment& OrderForDevelopment : OrdersForDevelopment) {
		if (OrderForDevelopment.getBranch() == branchNumber && !OrderForDevelopment.getExpress()) {
			ns = ns + OrderForDevelopment.getNumFilms();
		}
		else if (OrderForDevelopment.getBranch() == branchNumber && OrderForDevelopment.getExpress()) {
			ne = ne + OrderForDevelopment.getNumFilms();
		}
	}
	for (const CombinedOrder& CombinedOrder : CombinedOrders) {
		if (CombinedOrder.getBranch() == branchNumber && !CombinedOrder.getExpress()) {
			ns = ns + CombinedOrder.getNumPhotos();
		}
		else if (CombinedOrder.getBranch() == branchNumber && CombinedOrder.getExpress()) {
			ne = ne + CombinedOrder.getNumPhotos();
		}
	}
	cout << "З простих замовлень: " << ns << endl;
	cout << "З термінових замовлень: " << ne << endl;
	cout << "Загалом: " << ns + ne << endl;

}
void printKioskNumOfFilms(const Orders& orders, int kioskNumber)
{
	const vector<OrderForDevelopment>& OrdersForDevelopment = orders.getOrdersForDevelopment();
	const vector<CombinedOrder>& CombinedOrders = orders.getCombinedOrders();

	int ns = 0;

	cout << "------------------------------------------------------------------------\n";
	cout << "Звіт кіоску №" << kioskNumber << endl << endl;
	cout << "Кількість проявлених фотоплівок за тиждень:" << endl << endl;
	for (const OrderForDevelopment& OrderForDevelopment : OrdersForDevelopment) {
		if (OrderForDevelopment.getKiosk() == kioskNumber && !OrderForDevelopment.getExpress()) {
			ns = ns + OrderForDevelopment.getNumFilms();
		}
	}
	for (const CombinedOrder& CombinedOrder : CombinedOrders) {
		if (CombinedOrder.getKiosk() == kioskNumber && !CombinedOrder.getExpress()) {
			ns = ns + CombinedOrder.getNumFilms();
		}
	}
	cout << "З простих замовлень: " << ns << endl;
}

//Перелік поставок
void printSuppliers(const PhotoCenter& photoCenter)
{
	const vector<Supplier>& Suppliers = photoCenter.getSuppliers();

	cout << "------------------------------------------------------------------------\n";
	cout << "Перелік постачальників по фото центру:" << endl << endl;
	for (const Supplier& Supplier : Suppliers) {
			cout <<"Постачальник №" << Supplier.getNum() << endl;
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "Перелік постачальників та обсягів поставок фотоплівок протягом тижня:" << endl << endl;
	for (const Supplier& Supplier : Suppliers) {
		if (Supplier.getFilms()) {
			cout << "\nПостачальник №" << Supplier.getNum() << endl;
			cout <<"Фірма: " << Supplier.getName() << " |  Кількість: " << Supplier.getNumOfFilms() << " шт." << endl;
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "Перелік постачальників та обсягів поставок фотоапаратів протягом тижня:" << endl << endl;
	for (const Supplier& Supplier : Suppliers) {
		if (Supplier.getCameras()) {
			cout << "\nПостачальник №" << Supplier.getNum() << endl;
			cout << "Фірма: " << Supplier.getName() << " |  Кількість: " << Supplier.getNumOfCamaras() << " шт." << endl;
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "Перелік постачальників та обсягів поставок альбомів протягом тижня:" << endl << endl;
	for (const Supplier& Supplier : Suppliers) {
		if (Supplier.getAlbums()) {
			cout << "\nПостачальник №" << Supplier.getNum() << endl;
			cout << "Фірма: " << Supplier.getName() << " |  Кількість: " << Supplier.getNumOfAlbums() << " шт." << endl;
		}
	}
}

//Перелік клієнтів
void printСlientListOfPhotoCenter(const PhotoCenter& photoCenter)
{
	const vector<Client>& Clients = photoCenter.getClients();

	cout << "------------------------------------------------------------------------\n";
	cout << "Перелік клієнтів в цілому по фото центру:" << endl ;
	cout << "------------------------------------------------------------------------\n";
	cout << "Які мають знижки:" << endl << endl;
	for (const Client& Client : Clients) {
		if (Client.getDiscountCard() && Client.getProfessional()) {
			cout << "Прізвище та ім'я: " << Client.getName() << " (Професіонал з дисконтною карткою)" << endl;
		}
		else if (!Client.getDiscountCard() && Client.getProfessional()) {
			cout << "Прізвище та ім'я: " << Client.getName() << " (Професіонал без дисконтної картки)" << endl;
		}
		else if (Client.getDiscountCard() && !Client.getProfessional()) {
			cout << "Прізвище та ім'я: " << Client.getName() << " (Любитель з дисконтною карткою)" << endl;
		}
	}
	cout << "------------------------------------------------------------------------\n";
	cout << "Які зробили замовлення певного обсягу:" << endl << endl;
	for (const Client& Client : Clients) {
		if (Client.getMadeOrder()) {
			if (Client.getDiscountCard() && Client.getProfessional()) {
				cout << "Прізвище та ім'я: " << Client.getName() << " (Професіонал з дисконтною карткою)" << endl;
			}
			else if (!Client.getDiscountCard() && Client.getProfessional()) {
				cout << "Прізвище та ім'я: " << Client.getName() << " (Професіонал без дисконтної картки)" << endl;
			}
			else if (Client.getDiscountCard() && !Client.getProfessional()) {
				cout << "Прізвище та ім'я: " << Client.getName() << " (Любитель з дисконтною карткою)" << endl;
			}
			else {
				cout << "Прізвище та ім'я: " << Client.getName() << " (Любитель без дисконтної картки)" << endl;
			}
		}
	}
}
void printСlientListOfBranch(const PhotoCenter& photoCenter, int branchNumber)
{
	const vector<Client>& Clients = photoCenter.getClients();

	cout << "------------------------------------------------------------------------\n";
	cout << "Перелік клієнтів філії №:" << branchNumber << endl;
	cout << "------------------------------------------------------------------------\n";
	cout << "Які мають знижки:" << endl << endl;
	for (const Client& Client : Clients) {
		if (Client.getBranch() == branchNumber){
			if (Client.getDiscountCard() && Client.getProfessional()) {
				cout << "Прізвище та ім'я: " << Client.getName() << " (Професіонал з дисконтною карткою)" << endl;
			}
			else if (!Client.getDiscountCard() && Client.getProfessional()) {
				cout << "Прізвище та ім'я: " << Client.getName() << " (Професіонал без дисконтної картки)" << endl;
			}
			else if (Client.getDiscountCard() && !Client.getProfessional()) {
				cout << "Прізвище та ім'я: " << Client.getName() << " (Любитель з дисконтною карткою)" << endl;
			}
		}
	}
	cout << "------------------------------------------------------------------------\n";
	cout << "Які зробили замовлення певного обсягу:" << endl << endl;
	for (const Client& Client : Clients) {
		if (Client.getMadeOrder() && Client.getBranch() == branchNumber) {
			if (Client.getDiscountCard() && Client.getProfessional()) {
				cout << "Прізвище та ім'я: " << Client.getName() << " (Професіонал з дисконтною карткою)" << endl;
			}
			else if (!Client.getDiscountCard() && Client.getProfessional()) {
				cout << "Прізвище та ім'я: " << Client.getName() << " (Професіонал без дисконтної картки)" << endl;
			}
			else if (Client.getDiscountCard() && !Client.getProfessional()) {
				cout << "Прізвище та ім'я: " << Client.getName() << " (Любитель з дисконтною карткою)" << endl;
			}
			else {
				cout << "Прізвище та ім'я: " << Client.getName() << " (Любитель без дисконтної картки)" << endl;
			}
		}
	}
}

//Вивід суми виручки з проданих фототоварів
void printPhotoCenterProfitFromSoldProducts(const PhotoCenter& photoCenter)
{
	int numOfFilms = 0, numOfCamaras = 0, numOfAlbums = 0;
	int pricePerFilm = 400,
		pricePerCamera = 16000 ,
		pricePerAlbum = 600;

	const vector<Product>& Products = photoCenter.getProducts();

	cout << "------------------------------------------------------------------------\n";
	cout << "Сума виручки з проданих фототоварів протягом тижня в цілому по фото центру:" << endl << endl;

	for (const Product& Product : Products) {
		if (Product.getFilms()) {
			numOfFilms = numOfFilms + Product.getNumOfFilms();
		}
		else if (Product.getCameras()) {
			numOfCamaras = numOfCamaras + Product.getNumOfCamaras();
		}
		else if (Product.getAlbums()) {
			numOfAlbums = numOfAlbums + Product.getNumOfAlbums();
		}
	}

	cout << "Фотоплівок: " << numOfFilms * pricePerFilm << " грн." << endl << endl;

	cout << "Фотоапаратів: " << numOfCamaras * pricePerCamera << " грн." << endl << endl;

	cout << "Альбомів: " << numOfAlbums * pricePerAlbum << " грн." << endl << endl;

}
void printBranchProfitFromSoldProducts(const PhotoCenter& photoCenter, int branchNumber)
{
	int numOfFilms = 0, numOfCamaras = 0, numOfAlbums = 0;
	int pricePerFilm = 400,
		pricePerCamera = 16000,
		pricePerAlbum = 600;

	const vector<Product>& Products = photoCenter.getProducts();

	cout << "------------------------------------------------------------------------\n";
	cout << "Сума виручки з проданих фототоварів протягом тижня у філії №: " << branchNumber << endl << endl;

	for (const Product& Product : Products) {
		if (Product.getBranch() == branchNumber) {
			if (Product.getFilms()) {
				numOfFilms = numOfFilms + Product.getNumOfFilms();
			}
			else if (Product.getCameras()) {
				numOfCamaras = numOfCamaras + Product.getNumOfCamaras();
			}
			else if (Product.getAlbums()) {
				numOfAlbums = numOfAlbums + Product.getNumOfAlbums();
			}
		}
	}

	cout << "Фотоплівок: " << numOfFilms * pricePerFilm << " грн." << endl << endl;

	cout << "Фотоапаратів: " << numOfCamaras * pricePerCamera << " грн." << endl << endl;

	cout << "Альбомів: " << numOfAlbums * pricePerAlbum << " грн." << endl << endl;
}

//Перелік фототоварів і фірм-виробників, які користуються найбільшим попитом
void printTopPhotoCenterSoldProducts(const PhotoCenter& photoCenter)
{
	int maxNum = 0;
	const vector<Product>& Products = photoCenter.getProducts();

	

	for (const Product& Product : Products) {
		if (Product.getNumOfFilms() > maxNum) {
			maxNum = Product.getNumOfFilms();
		}
		else if (Product.getNumOfCamaras() > maxNum) {
			maxNum = Product.getNumOfCamaras();
		}
		else if (Product.getNumOfAlbums() > maxNum) {
			maxNum = Product.getNumOfAlbums();
		}
	}
	cout << "------------------------------------------------------------------------\n";
	cout << "Перелік фототоварів і фірм-виробників, які користуються найбільшим попитом в цілому по фото центру:" << endl << endl;
	for (const Product& Product : Products) {
		if (Product.getNumOfFilms() == maxNum) {
			cout << "Фірма: " << Product.getName() << " |  Фотоплівки: " << Product.getNumOfFilms()<<" шт."<<endl;
		}
		else if (Product.getNumOfCamaras() == maxNum) {
			cout << "Фірма: " << Product.getName() << " |  Фотоапарати: " << Product.getNumOfCamaras() << " шт." << endl;
		}
		else if (Product.getNumOfAlbums() == maxNum) {
			cout << "Фірма: " << Product.getName() << " |  Альбоми: " << Product.getNumOfAlbums() << " шт." << endl;
		}
	}
}
void printTopBranchSoldProducts(const PhotoCenter& photoCenter, int branchNumber)
{
	int maxNum = 0;
	const vector<Product>& Products = photoCenter.getProducts();

	for (const Product& Product : Products) {
		if (Product.getBranch() == branchNumber) {
			if (Product.getNumOfFilms() > maxNum) {
				maxNum = Product.getNumOfFilms();
			}
			else if (Product.getNumOfCamaras() > maxNum) {
				maxNum = Product.getNumOfCamaras();
			}
			else if (Product.getNumOfAlbums() > maxNum) {
				maxNum = Product.getNumOfAlbums();
			}
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "Перелік фототоварів і фірм-виробників, які користуються найбільшим попитом в філії №:" << branchNumber << endl << endl;
	for (const Product& Product : Products) {
		if (Product.getBranch() == branchNumber) {
			if (Product.getNumOfFilms() == maxNum) {
				cout << "Фірма: " << Product.getName() << " |  Фотоплівки: " << Product.getNumOfFilms() << " шт." << endl;
			}
			else if (Product.getNumOfCamaras() == maxNum) {
				cout << "Фірма: " << Product.getName() << " |  Фотоапарати: " << Product.getNumOfCamaras() << " шт." << endl;
			}
			else if (Product.getNumOfAlbums() == maxNum) {
				cout << "Фірма: " << Product.getName() << " |  Альбоми: " << Product.getNumOfAlbums() << " шт." << endl;
			}
		}
	}
}

//Перелік проданих фототоварів
void printPhotoCenterSoldProducts(const PhotoCenter& photoCenter)
{
	int numOfFilms = 0, numOfCamaras = 0, numOfAlbums = 0;

	const vector<Product>& Products = photoCenter.getProducts();

	cout << "------------------------------------------------------------------------\n";
	cout << "Перелік проданих фототоварів протягом тижня та їх обсяги в цілому по фото центру:" << endl << endl;

	for (const Product& Product : Products) {
		if (Product.getFilms()) {
			numOfFilms = numOfFilms + Product.getNumOfFilms();
		}
		else if(Product.getCameras()) {
			numOfCamaras = numOfCamaras + Product.getNumOfCamaras();
		}
		else if (Product.getAlbums()) {
			numOfAlbums = numOfAlbums + Product.getNumOfAlbums();
		}
	}

	cout << "Фотоплівок: " << numOfFilms << " шт." << endl << endl;

	cout << "Фотоапаратів: "<< numOfCamaras << " шт." << endl << endl;
	
	cout << "Альбомів: "<< numOfAlbums << " шт." << endl << endl;
	
}
void printBranchSoldProducts(const PhotoCenter& photoCenter, int branchNumber)
{
	int numOfFilms = 0, numOfCamaras = 0, numOfAlbums = 0;

	const vector<Product>& Products = photoCenter.getProducts();

	cout << "------------------------------------------------------------------------\n";
	cout << "Перелік проданих фототоварів протягом тижня та їх обсяги у філії №: " << branchNumber << endl << endl;

	for (const Product& Product : Products) {
		if(Product.getBranch() == branchNumber) {
			if (Product.getFilms()) {
				numOfFilms = numOfFilms + Product.getNumOfFilms();
			}
			else if (Product.getCameras()) {
				numOfCamaras = numOfCamaras + Product.getNumOfCamaras();
			}
			else if (Product.getAlbums()) {
				numOfAlbums = numOfAlbums + Product.getNumOfAlbums();
			}
		}
	}

	cout << "Фотоплівок: " << numOfFilms << " шт." << endl << endl;

	cout << "Фотоапаратів: " << numOfCamaras << " шт." << endl << endl;

	cout << "Альбомів: " << numOfAlbums << " шт." << endl << endl;

}

//Перелік робочих місць
void printListOfWorkers(const PhotoCenter& photoCenter)
{
	const vector<Worker>& Workers = photoCenter.getWorkers();

	cout << "------------------------------------------------------------------------\n";
	cout << "Перелік робочих місць в цілому по фото центру:" << endl;
	
	cout << "------------------------------------------------------------------------\n";
	cout << "Директор фотоцентру" << endl;
	for (const Worker& Worker : Workers) {
		if (Worker.getPost() == "Директор фотоцентру") {
			cout << "Прізвище та ім'я: " << Worker.getName() << endl;
		}
	}
	
	cout << "------------------------------------------------------------------------\n";
	cout << "Менеджери відділень:" << endl << endl;
	for (const Worker& Worker : Workers) {
		if (Worker.getPost() == "Менеджер відділення") {
			if (Worker.getBranch() != NULL) {
				cout << "Прізвище та ім'я: " << Worker.getName() << " |  Працівник філії №" << Worker.getBranch() << endl;
			}
			else if (Worker.getKiosk() != NULL) {
				cout << "Прізвище та ім'я: " << Worker.getName() << " |  Працівник кіоску №" << Worker.getKiosk() << endl;
			}
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "Менеджери прийому замовлень: " << endl << endl;
	for (const Worker& Worker : Workers) {
		if (Worker.getPost() == "Менеджер прийому замовлень") {
			if (Worker.getBranch() != NULL) {
				cout << "Прізвище та ім'я: " << Worker.getName() << " |  Працівник філії №" << Worker.getBranch() << endl;
			}
			else if (Worker.getKiosk() != NULL) {
				cout << "Прізвище та ім'я: " << Worker.getName() << " |  Працівник кіоску №" << Worker.getKiosk() << endl;
			}
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "Менеджери поставок: " << endl << endl;
	for (const Worker& Worker : Workers) {
		if (Worker.getPost() == "Менеджер поставок") {
			if (Worker.getBranch() != NULL) {
				cout << "Прізвище та ім'я: " << Worker.getName() << " |  Працівник філії №" << Worker.getBranch() << endl;
			}
			else if (Worker.getKiosk() != NULL) {
				cout << "Прізвище та ім'я: " << Worker.getName() << " |  Працівник кіоску №" << Worker.getKiosk() << endl;
			}
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "Друкарі (відповідають за друк фотографій): " << endl << endl;
	for (const Worker& Worker : Workers) {
		if (Worker.getPost() == "Друкар") {
			if (Worker.getBranch() != NULL) {
				cout << "Прізвище та ім'я: " << Worker.getName() << " |  Працівник філії №" << Worker.getBranch() << endl;
			}
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "Фотолаборанти (відповідають за проявлення фотоплівок): " << endl << endl;
	for (const Worker& Worker : Workers) {
		if (Worker.getPost() == "Фотолаборант") {
			if (Worker.getBranch() != NULL) {
				cout << "Прізвище та ім'я: " << Worker.getName() << " |  Працівник філії №" << Worker.getBranch() << endl;
			}
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "Продавці фототоварів: " << endl << endl;
	for (const Worker& Worker : Workers) {
		if (Worker.getPost() == "Продавець фототоварів") {
			if (Worker.getBranch() != NULL) {
				cout << "Прізвище та ім'я: " << Worker.getName() << " |  Працівник філії №" << Worker.getBranch() << endl;
			}
			else if (Worker.getKiosk() != NULL) {
				cout << "Прізвище та ім'я: " << Worker.getName() << " |  Працівник кіоску №" << Worker.getKiosk() << endl;
			}
		}
	}
}
void printListOfPost(const PhotoCenter& photoCenter)
{
	const vector<Worker>& Workers = photoCenter.getWorkers();
	int choice;
	cout << "------------------------------------------------------------------------\n";
	cout << "Отримати перелік робочих місць на посаді:" << endl
		<< "1. Директор фотоцентру" << endl
		<< "2. Менеджер відділення" << endl
		<< "3. Менеджер прийому замовлень" << endl
		<< "4. Менеджер поставок" << endl
		<< "5. Друкар" << endl
		<< "6. Фотолаборант" << endl
		<< "7. Продавець фототоварів" << endl;
	cin >> choice;

	cout << "------------------------------------------------------------------------\n";
	cout << "Перелік робочих місць по зазначеному профілю:" << endl;
	if (choice == 1) {
		cout << "------------------------------------------------------------------------\n";
		cout << "Директор фотоцентру" << endl;
		for (const Worker& Worker : Workers) {
			if (Worker.getPost() == "Директор фотоцентру") {
				cout << "Прізвище та ім'я: " << Worker.getName() << endl;
			}
		}
	}
	else if (choice == 2) {
		cout << "------------------------------------------------------------------------\n";
		cout << "Менеджери відділень:" << endl << endl;
		for (const Worker& Worker : Workers) {
			if (Worker.getPost() == "Менеджер відділення") {
				if (Worker.getBranch() != NULL) {
					cout << "Прізвище та ім'я: " << Worker.getName() << " |  Працівник філії №" << Worker.getBranch() << endl;
				}
				else if (Worker.getKiosk() != NULL) {
					cout << "Прізвище та ім'я: " << Worker.getName() << " |  Працівник кіоску №" << Worker.getKiosk() << endl;
				}
			}
		}
	}
	else if (choice == 3) {
		cout << "------------------------------------------------------------------------\n";
		cout << "Менеджери прийому замовлень: " << endl << endl;
		for (const Worker& Worker : Workers) {
			if (Worker.getPost() == "Менеджер прийому замовлень") {
				if (Worker.getBranch() != NULL) {
					cout << "Прізвище та ім'я: " << Worker.getName() << " |  Працівник філії №" << Worker.getBranch() << endl;
				}
				else if (Worker.getKiosk() != NULL) {
					cout << "Прізвище та ім'я: " << Worker.getName() << " |  Працівник кіоску №" << Worker.getKiosk() << endl;
				}
			}
		}
	}
	else if (choice == 4) {
		cout << "------------------------------------------------------------------------\n";
		cout << "Менеджери поставок: " << endl << endl;
		for (const Worker& Worker : Workers) {
			if (Worker.getPost() == "Менеджер поставок") {
				if (Worker.getBranch() != NULL) {
					cout << "Прізвище та ім'я: " << Worker.getName() << " |  Працівник філії №" << Worker.getBranch() << endl;
				}
				else if (Worker.getKiosk() != NULL) {
					cout << "Прізвище та ім'я: " << Worker.getName() << " |  Працівник кіоску №" << Worker.getKiosk() << endl;
				}
			}
		}
	}
	else if (choice == 5) {
		cout << "------------------------------------------------------------------------\n";
		cout << "Друкарі (відповідають за друк фотографій): " << endl << endl;
		for (const Worker& Worker : Workers) {
			if (Worker.getPost() == "Друкар") {
				if (Worker.getBranch() != NULL) {
					cout << "Прізвище та ім'я: " << Worker.getName() << " |  Працівник філії №" << Worker.getBranch() << endl;
				}
			}
		}
	}
	else if (choice == 6) {
		cout << "------------------------------------------------------------------------\n";
		cout << "Фотолаборанти (відповідають за проявлення фотоплівок): " << endl << endl;
		for (const Worker& Worker : Workers) {
			if (Worker.getPost() == "Фотолаборант") {
				if (Worker.getBranch() != NULL) {
					cout << "Прізвище та ім'я: " << Worker.getName() << " |  Працівник філії №" << Worker.getBranch() << endl;
				}
			}
		}
	}
	else if (choice == 7) {
		cout << "------------------------------------------------------------------------\n";
		cout << "Продавці фототоварів: " << endl << endl;
		for (const Worker& Worker : Workers) {
			if (Worker.getPost() == "Продавець фототоварів") {
				if (Worker.getBranch() != NULL) {
					cout << "Прізвище та ім'я: " << Worker.getName() << " |  Працівник філії №" << Worker.getBranch() << endl;
				}
				else if (Worker.getKiosk() != NULL) {
					cout << "Прізвище та ім'я: " << Worker.getName() << " |  Працівник кіоску №" << Worker.getKiosk() << endl;
				}
			}
		}
	}
}