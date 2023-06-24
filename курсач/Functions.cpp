#include "Data.h"


//���������� ���� �������
void branchProfitFromOrders�alc(const Orders& orders, Revenue& revenue, int branchNumber)
{
	float pricePerPhoto10x15, pricePerPhoto15x21, pricePerPhoto21x30, pricePerPhoto30x45, pricePerFilm,
		pricePerPrint = 0, pricePerDevelop = 0,
		pricePerPrintExpress = 0, pricePerDevelopExpress = 0, pricePerCombinedExpress = 0,
		revenueFromPrint = 0, revenueFromDevelop = 0, revenueFromCombined = 0,
		revenueFromPrintExpress = 0, revenueFromDevelopExpress = 0, revenueFromCombinedExpress = 0;

	const vector<OrderForPrint>& OrdersForPrint = orders.getOrdersForPrint();
	const vector<OrderForDevelopment>& OrdersForDevelopment = orders.getOrdersForDevelopment();
	const vector<CombinedOrder>& CombinedOrders = orders.getCombinedOrders();

	//������� �� ����
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
//������� �� ����������
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
//������� �� ���� � ����������
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
void kioskProfitFromOrders�alc(const Orders& orders, Revenue& revenue, int kioskNumber)
{
	float pricePerPhoto10x15, pricePerPhoto15x21, pricePerPhoto21x30, pricePerPhoto30x45, pricePerFilm,
		pricePerPrint = 0, pricePerDevelop = 0,
		revenueFromPrint = 0, revenueFromDevelop = 0, revenueFromCombined = 0;

	const vector<OrderForPrint>& OrdersForPrint = orders.getOrdersForPrint();
	const vector<OrderForDevelopment>& OrdersForDevelopment = orders.getOrdersForDevelopment();
	const vector<CombinedOrder>& CombinedOrders = orders.getCombinedOrders();

	//������� �� ����
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
	//������� �� ����������
	for (const OrderForDevelopment& OrderForDevelopment : OrdersForDevelopment) {
		if (OrderForDevelopment.getKiosk() == kioskNumber) {
			if (!OrderForDevelopment.getBoughtHere()) {
				pricePerFilm = 150;
				pricePerDevelop = OrderForDevelopment.getNumFilms() * pricePerFilm;

				revenueFromDevelop = revenueFromDevelop + pricePerDevelop;
			}
		}
	}

	//������� �� ���� � ����������
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

//������ ���� �� �����
void printBranchesAndKiosks(const PhotoCenter& photoCenter)
{
	const vector<Branch>& branches = photoCenter.getBranches();
	const vector<Kiosk>& kiosks = photoCenter.getKiosks();

	cout << "------------------------------------------------------------------------\n";
	cout << "Գ볿:" << endl;
	cout << "------------------------------------------------------------------------\n";
	for (const Branch& branch : branches) {
		cout << "Գ�� �" << branch.getBranchNum() << endl;
		cout << "������: " << branch.getAddress() << endl;
		cout << endl;
		cout << "------------------------------------------------------------------------\n";
		cout << "ʳ����, ��������� �� ��볿 �" << branch.getBranchNum() << ":" << endl;
		for (const Kiosk& kiosk : kiosks) {
			if (kiosk.getAttachedBranch() == branch.getBranchNum()) {
				cout << "\nʳ��� �" << kiosk.getKioskNum() << endl;
				cout << "������: " << kiosk.getAddress() << endl;
				cout << endl;
			}
		}
		cout << "------------------------------------------------------------------------\n------------------------------------------------------------------------\n";
	}
}

//������ ��� ���������
void printOrders(const Orders& orders)
{
	int nb = 0, nk = 0, i;
	const vector<OrderForPrint>& OrdersForPrint = orders.getOrdersForPrint();
	const vector<OrderForDevelopment>& OrdersForDevelopment = orders.getOrdersForDevelopment();
	const vector<CombinedOrder>& CombinedOrders = orders.getCombinedOrders();
	
	cout << "------------------------------------------------------------------------\n";
	cout << "������ ��������� �� ����� �� �������:" << endl;
	cout << "------------------------------------------------------------------------\n";
	cout << "�� ���� ����������:\n";
	i = 1;
	for (const OrderForPrint& OrderForPrint : OrdersForPrint) {
		if (OrderForPrint.getBranch() != NULL)
		{
			cout << "\n���������� �" << i << endl
				<< "ʳ������ ���� � ������� �����: " << OrderForPrint.getNumPhotosPF() << ";  (�������� ������� ����: " << OrderForPrint.getNumPhotos() << ")" << endl
				<< "��� ������: " << OrderForPrint.getPaperType() << ";  ������: " << OrderForPrint.getFormat() << endl;
			cout << "��� ����������: ";
			if (OrderForPrint.getExpress()) {
				cout << "��������" << endl;
			}
			else {
				cout << "������" << endl;
			}
			i++;
			nb = nb + 1;
		}
	}
	
	cout << "------------------------------------------------------------------------\n";
	cout << "�� ���������� ���������:\n";
	i = 1;
	for (const OrderForDevelopment& OrderForDevelopment : OrdersForDevelopment) {
		if (OrderForDevelopment.getBranch() != NULL)
		{
			cout << "\n���������� �" << i << endl
				<< "ʳ������ ����� ��� ����������: " << OrderForDevelopment.getNumFilms() << endl;
			cout << "��� ����������: ";
			if (OrderForDevelopment.getExpress()) {
				cout << "��������" << endl;
			}
			else {
				cout << "������" << endl;
			}
			i++;
			nb = nb + 1;
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "�� ���� �� ���������� �����:\n";
	i = 1;
	for (const CombinedOrder& CombinedOrder : CombinedOrders) {
		if (CombinedOrder.getBranch() != NULL)
		{
			cout << "\n���������� �" << i << endl
				<< "ʳ������ ���� � ������� �����: " << CombinedOrder.getNumPhotosPF() << ";  (�������� ������� ����: " << CombinedOrder.getNumPhotos() << ")" << endl
				<< "��� ������: " << CombinedOrder.getPaperType() << ";  ������: " << CombinedOrder.getFormat() << endl
				<< "ʳ������ ����� ��� ����������: " << CombinedOrder.getNumFilms() << endl;
			cout << "��� ����������: ";
			if (CombinedOrder.getExpress()) {
				cout << "��������" << endl;
			}
			else {
				cout << "������" << endl;
			}
			i++;
			nb = nb + 1;
		}
	}
	cout << "------------------------------------------------------------------------\n";
	
	cout << "������ ��������� �� ������ �� �������:" << endl;
	cout << "------------------------------------------------------------------------\n";
	cout << "�� ���� ����������:\n";
	i = 1;
	for (const OrderForPrint& OrderForPrint : OrdersForPrint) {
		if (OrderForPrint.getKiosk() != NULL)
		{
			cout << "\n���������� �" << i << endl
				<< "ʳ������ ���� � ������� �����: " << OrderForPrint.getNumPhotosPF() << ";  (�������� ������� ����: " << OrderForPrint.getNumPhotos() << ")" << endl
				<< "��� ������: " << OrderForPrint.getPaperType() << ";  ������: " << OrderForPrint.getFormat() << endl;
			cout << "��� ����������: ������" << endl;
			i++;
			nk = nk + 1;
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "�� ���������� ���������:\n";
	i = 1;
	for (const OrderForDevelopment& OrderForDevelopment : OrdersForDevelopment) {
		if (OrderForDevelopment.getKiosk() != NULL)
		{
			cout << "\n���������� �" << i << endl
				<< "ʳ������ ����� ��� ����������: " << OrderForDevelopment.getNumFilms() << endl;
			cout << "��� ����������: ������" << endl;
			i++;
			nk = nk + 1;
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "�� ���� �� ���������� �����:\n";
	i = 1;
	for (const CombinedOrder& CombinedOrder : CombinedOrders) {
		if (CombinedOrder.getKiosk() != NULL)
		{
			cout << "\n���������� �" << i << endl
				<< "ʳ������ ���� � ������� �����: " << CombinedOrder.getNumPhotosPF() << ";  (�������� ������� ����: " << CombinedOrder.getNumPhotos() << ")" << endl
				<< "��� ������: " << CombinedOrder.getPaperType() << ";  ������: " << CombinedOrder.getFormat() << endl
				<< "ʳ������ ����� ��� ����������: " << CombinedOrder.getNumFilms() << endl;
			cout << "��� ����������: ������" << endl;
			i++;
			nk = nk + 1;
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "�������� ������� ��������� �� ����� �� �������: " << nb << endl;
	cout << "------------------------------------------------------------------------\n";
	cout << "�������� ������� ��������� �� ������ �� �������: " << nk << endl;
	cout << "------------------------------------------------------------------------\n";
	cout << "�������� ������� ��������� �� ���� ������ �� �������: " << nb + nk << endl;
}

//������ ��� ��������� (������ ������� �� ���������)
void printOrdersForBranchByNumber(const Orders& orders, int branchNumber) 
{
	int nb = 0, nbe = 0, i;
	
	const vector<OrderForPrint>& OrdersForPrint = orders.getOrdersForPrint();
	const vector<OrderForDevelopment>& OrdersForDevelopment = orders.getOrdersForDevelopment();
	const vector<CombinedOrder>& CombinedOrders = orders.getCombinedOrders();

	cout << "------------------------------------------------------------------------\n";
	cout << "��� ��볿 �" << branchNumber << endl;
	cout << "------------------------------------------------------------------------\n";
	cout << "������ ������� ��������� �� �������:" << endl;

	cout << "------------------------------------------------------------------------\n";
	cout << "�� ���� ����������:\n";
	i = 1;
	for (const OrderForPrint& OrderForPrint : OrdersForPrint) {
		if (OrderForPrint.getBranch() == branchNumber && !OrderForPrint.getExpress()) {
			cout << "\n���������� �" << i << endl
				<< "ʳ������ ���� � ������� �����: " << OrderForPrint.getNumPhotosPF() << " |	�������� ������� ����: " << OrderForPrint.getNumPhotos() << endl
				<< "��� ������: " << OrderForPrint.getPaperType() << " |  ������: " << OrderForPrint.getFormat() << endl;
			i++;
			nb = nb + 1;
		}
	}

	cout << "\n------------------------------------------------------------------------\n";
	cout << "�� ���������� ���������:\n";
	i = 1;
	for (const OrderForDevelopment& OrderForDevelopment : OrdersForDevelopment) {
		if (OrderForDevelopment.getBranch() == branchNumber && !OrderForDevelopment.getExpress()) {
			cout << "\n���������� �" << i << endl
				<< "ʳ������ ����� ��� ����������: " << OrderForDevelopment.getNumFilms() << endl;
			i++;
			nb = nb + 1;
		}
	}

	cout << "\n------------------------------------------------------------------------\n";
	cout << "�� ���� �� ���������� �����:\n";
	i = 1;
	for (const CombinedOrder& CombinedOrder : CombinedOrders) {
		if (CombinedOrder.getBranch() == branchNumber && !CombinedOrder.getExpress()) {
			cout << "\n���������� �" << i << endl
				<< "ʳ������ ���� � ������� �����: " << CombinedOrder.getNumPhotosPF() << " |	�������� ������� ����: " << CombinedOrder.getNumPhotos() << endl
				<< "��� ������: " << CombinedOrder.getPaperType() << " |  ������: " << CombinedOrder.getFormat() << endl
				<< "ʳ������ ����� ��� ����������: " << CombinedOrder.getNumFilms() << endl;
			i++;
			nb = nb + 1;
		}
	}

	cout << "\n------------------------------------------------------------------------\n";
	cout << "������ ��������� ��������� ��� ��볿 �" << branchNumber << " �� �������:" << endl;

	cout << "------------------------------------------------------------------------\n";
	cout << "�� ���� ����������:\n";
	i = 1;
	for (const OrderForPrint& OrderForPrint : OrdersForPrint) {
		if (OrderForPrint.getBranch() == branchNumber && OrderForPrint.getExpress()) {
			cout << "\n���������� �" << i << endl
				<< "ʳ������ ���� � ������� �����: " << OrderForPrint.getNumPhotosPF() << " |	�������� ������� ����: " << OrderForPrint.getNumPhotos() << endl
				<< "��� ������: " << OrderForPrint.getPaperType() << " |  ������: " << OrderForPrint.getFormat() << endl;
			i++;
			nbe = nbe + 1;
		}
	}

	cout << "\n------------------------------------------------------------------------\n";
	cout << "�� ���������� ���������:\n";
	i = 1;
	for (const OrderForDevelopment& OrderForDevelopment : OrdersForDevelopment) {
		if (OrderForDevelopment.getBranch() == branchNumber && OrderForDevelopment.getExpress()) {
			cout << "\n���������� �" << i << endl
				<< "ʳ������ ����� ��� ����������: " << OrderForDevelopment.getNumFilms() << endl;
			i++;
			nbe = nbe + 1;
		}
	}

	cout << "\n------------------------------------------------------------------------\n";
	cout << "�� ���� �� ���������� �����:\n";
	i = 1;
	for (const CombinedOrder& CombinedOrder : CombinedOrders) {
		if (CombinedOrder.getBranch() == branchNumber && CombinedOrder.getExpress()) {
			cout << "\n���������� �" << i << endl
				<< "ʳ������ ���� � ������� �����: " << CombinedOrder.getNumPhotosPF() << " |	�������� ������� ����: " << CombinedOrder.getNumPhotos() << endl
				<< "��� ������: " << CombinedOrder.getPaperType() << " |  ������: " << CombinedOrder.getFormat() << endl
				<< "ʳ������ ����� ��� ����������: " << CombinedOrder.getNumFilms() << endl;
			i++;
			nbe = nbe + 1;
		}
	}

	cout << "\n------------------------------------------------------------------------\n";
	cout << "�������� ������� ������� ��������� ��� ������� ��볿 �� �������: " << nb << endl;
	cout << "------------------------------------------------------------------------\n";
	cout << "�������� ������� ��������� ��������� ��� ������� ��볿 �� �������: " << nbe << endl;
	cout << "------------------------------------------------------------------------\n";
}
void printOrdersForKioskByNumber(const Orders& orders, int kioskNumber)
{
	int nk = 0, i;

	const vector<OrderForPrint>& OrdersForPrint = orders.getOrdersForPrint();
	const vector<OrderForDevelopment>& OrdersForDevelopment = orders.getOrdersForDevelopment();
	const vector<CombinedOrder>& CombinedOrders = orders.getCombinedOrders();

	cout << "------------------------------------------------------------------------\n";
	cout << "��� ����� �" << kioskNumber << endl;
	cout << "------------------------------------------------------------------------\n";
	cout << "������ ������� ��������� �� �������:" << endl;

	cout << "------------------------------------------------------------------------\n";
	cout << "�� ���� ����������:\n";
	i = 1;
	for (const OrderForPrint& OrderForPrint : OrdersForPrint) {
		if (OrderForPrint.getKiosk() == kioskNumber) {
			cout << "\n���������� �" << i << endl
				<< "ʳ������ ���� � ������� �����: " << OrderForPrint.getNumPhotosPF() << " |	�������� ������� ����: " << OrderForPrint.getNumPhotos() << endl
				<< "��� ������: " << OrderForPrint.getPaperType() << " |  ������: " << OrderForPrint.getFormat() << endl;
			i++;
			nk = nk + 1;
		}
	}

	cout << "\n------------------------------------------------------------------------\n";
	cout << "�� ���������� ���������:\n";
	i = 1;
	for (const OrderForDevelopment& OrderForDevelopment : OrdersForDevelopment) {
		if (OrderForDevelopment.getKiosk() == kioskNumber) {
			cout << "\n���������� �" << i << endl
				<< "ʳ������ ����� ��� ����������: " << OrderForDevelopment.getNumFilms() << endl;
			i++;
			nk = nk + 1;
		}
	}

	cout << "\n------------------------------------------------------------------------\n";
	cout << "�� ���� �� ���������� �����:\n";
	i = 1;
	for (const CombinedOrder& CombinedOrder : CombinedOrders) {
		if (CombinedOrder.getKiosk() == kioskNumber) {
			cout << "\n���������� �" << i << endl
				<< "ʳ������ ���� � ������� �����: " << CombinedOrder.getNumPhotosPF() << " |	�������� ������� ����: " << CombinedOrder.getNumPhotos() << endl
				<< "��� ������: " << CombinedOrder.getPaperType() << " |  ������: " << CombinedOrder.getFormat() << endl
				<< "ʳ������ ����� ��� ����������: " << CombinedOrder.getNumFilms() << endl;
			i++;
			nk = nk + 1;
		}
	}

	cout << "\n------------------------------------------------------------------------\n";
	cout << "�������� ������� ������� ��������� ��� ��������� ����� �� �������: " << nk << endl;
}

//���� ���� ������� 
void printBranchProfitFromOrders(const Orders& orders, const Revenue& revenue, int branchNumber)
{
	const vector<OrderForPrint>& OrdersForPrint = orders.getOrdersForPrint();
	const vector<OrderForDevelopment>& OrdersForDevelopment = orders.getOrdersForDevelopment();
	const vector<CombinedOrder>& CombinedOrders = orders.getCombinedOrders();
	const vector<RevenueFromExpressOrders>& RevenueFromExpressOrders_ = revenue.getRevenueFromExpressOrders_();

	for (const RevenueFromExpressOrders& RevenueFromExpressOrders : RevenueFromExpressOrders_) {
		cout << "------------------------------------------------------------------------\n";
		cout << "��� ��볿 �" << branchNumber << endl << endl;
		cout << "���� ������� �� ������� ��������� �� �������:" << endl;
		cout << "------------------------------------------------------------------------\n";
		cout << "� ��������� �� ���� ����������: " << RevenueFromExpressOrders.getRevenueFromPrint() << " ���." << endl << endl;
		cout << "� ��������� �� ���������� ���������: " << RevenueFromExpressOrders.getRevenueFromDevelop() << " ���." << endl << endl;
		cout << "� ��������� �� ���� � ���������� �����: " << RevenueFromExpressOrders.getRevenueFromCombined() << " ���." << endl;

		cout << "------------------------------------------------------------------------\n";
		cout << "���� ������� �� ��������� ��������� �� �������:" << endl;
		cout << "------------------------------------------------------------------------\n";
		cout << "� ��������� �� ���� ����������: " << RevenueFromExpressOrders.getRevenueFromPrintExpress() << " ���." << endl << endl;
		cout << "� ��������� �� ���������� ���������: " << RevenueFromExpressOrders.getRevenueFromDevelopExpress() << " ���." << endl << endl;
		cout << "� ��������� �� ���� � ���������� �����: " << RevenueFromExpressOrders.getRevenueFromCombinedExpress() << " ���." << endl;
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
		cout << "��� ����� �" << kioskNumber << endl << endl;
		cout << "���� ������� �� �������:" << endl;
		cout << "------------------------------------------------------------------------\n";
		cout << "� ��������� �� ���� ����������: " << RevenueFromSimpleOrders.getRevenueFromPrint() << " ���." << endl << endl;
		cout << "� ��������� �� ���������� ���������: " << RevenueFromSimpleOrders.getRevenueFromDevelop() << " ���." << endl << endl;
		cout << "� ��������� �� ���� � ���������� �����: " << RevenueFromSimpleOrders.getRevenueFromCombined() << " ���." << endl;
	}
}

//���� ������� ������������ ����������
void printBranchNumOfPhotos(const Orders& orders, int branchNumber)
{
	const vector<OrderForPrint>& OrdersForPrint = orders.getOrdersForPrint();
	const vector<CombinedOrder>& CombinedOrders = orders.getCombinedOrders();

	int ns = 0, ne = 0;

	cout << "------------------------------------------------------------------------\n";
	cout << "��� ��볿 �" << branchNumber << endl << endl;
	cout << "ʳ������ ������������ ���������� �� �������:" << endl << endl;
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
	cout << "� ������� ���������: "<< ns << endl;
	cout << "� ��������� ���������: " << ne << endl;
	cout << "�������: " << ns + ne << endl;
	
}
void printKioskNumOfPhotos(const Orders& orders, int kioskNumber)
{
	const vector<OrderForPrint>& OrdersForPrint = orders.getOrdersForPrint();
	const vector<CombinedOrder>& CombinedOrders = orders.getCombinedOrders();

	int ns = 0;

	cout << "------------------------------------------------------------------------\n";
	cout << "��� ����� �" << kioskNumber << endl << endl;
	cout << "ʳ������ ������������ ���������� �� �������:" << endl << endl;
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
	cout << "� ������� ���������: " << ns << endl;
}

//���� ������� ���������� ���������
void printBranchNumOfFilms(const Orders& orders, int branchNumber)
{
	const vector<OrderForDevelopment>& OrdersForDevelopment = orders.getOrdersForDevelopment();
	const vector<CombinedOrder>& CombinedOrders = orders.getCombinedOrders();

	int ns = 0, ne = 0;

	cout << "------------------------------------------------------------------------\n";
	cout << "��� ��볿 �" << branchNumber << endl << endl;
	cout << "ʳ������ ���������� ��������� �� �������:" << endl << endl;
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
	cout << "� ������� ���������: " << ns << endl;
	cout << "� ��������� ���������: " << ne << endl;
	cout << "�������: " << ns + ne << endl;

}
void printKioskNumOfFilms(const Orders& orders, int kioskNumber)
{
	const vector<OrderForDevelopment>& OrdersForDevelopment = orders.getOrdersForDevelopment();
	const vector<CombinedOrder>& CombinedOrders = orders.getCombinedOrders();

	int ns = 0;

	cout << "------------------------------------------------------------------------\n";
	cout << "��� ����� �" << kioskNumber << endl << endl;
	cout << "ʳ������ ���������� ��������� �� �������:" << endl << endl;
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
	cout << "� ������� ���������: " << ns << endl;
}

//������ ��������
void printSuppliers(const PhotoCenter& photoCenter)
{
	const vector<Supplier>& Suppliers = photoCenter.getSuppliers();

	cout << "------------------------------------------------------------------------\n";
	cout << "������ ������������� �� ���� ������:" << endl << endl;
	for (const Supplier& Supplier : Suppliers) {
			cout <<"������������ �" << Supplier.getNum() << endl;
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "������ ������������� �� ������ �������� ��������� �������� �����:" << endl << endl;
	for (const Supplier& Supplier : Suppliers) {
		if (Supplier.getFilms()) {
			cout << "\n������������ �" << Supplier.getNum() << endl;
			cout <<"Գ���: " << Supplier.getName() << " |  ʳ������: " << Supplier.getNumOfFilms() << " ��." << endl;
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "������ ������������� �� ������ �������� ����������� �������� �����:" << endl << endl;
	for (const Supplier& Supplier : Suppliers) {
		if (Supplier.getCameras()) {
			cout << "\n������������ �" << Supplier.getNum() << endl;
			cout << "Գ���: " << Supplier.getName() << " |  ʳ������: " << Supplier.getNumOfCamaras() << " ��." << endl;
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "������ ������������� �� ������ �������� ������� �������� �����:" << endl << endl;
	for (const Supplier& Supplier : Suppliers) {
		if (Supplier.getAlbums()) {
			cout << "\n������������ �" << Supplier.getNum() << endl;
			cout << "Գ���: " << Supplier.getName() << " |  ʳ������: " << Supplier.getNumOfAlbums() << " ��." << endl;
		}
	}
}

//������ �볺���
void print�lientListOfPhotoCenter(const PhotoCenter& photoCenter)
{
	const vector<Client>& Clients = photoCenter.getClients();

	cout << "------------------------------------------------------------------------\n";
	cout << "������ �볺��� � ������ �� ���� ������:" << endl ;
	cout << "------------------------------------------------------------------------\n";
	cout << "�� ����� ������:" << endl << endl;
	for (const Client& Client : Clients) {
		if (Client.getDiscountCard() && Client.getProfessional()) {
			cout << "������� �� ��'�: " << Client.getName() << " (���������� � ���������� �������)" << endl;
		}
		else if (!Client.getDiscountCard() && Client.getProfessional()) {
			cout << "������� �� ��'�: " << Client.getName() << " (���������� ��� ��������� ������)" << endl;
		}
		else if (Client.getDiscountCard() && !Client.getProfessional()) {
			cout << "������� �� ��'�: " << Client.getName() << " (�������� � ���������� �������)" << endl;
		}
	}
	cout << "------------------------------------------------------------------------\n";
	cout << "�� ������� ���������� ������� ������:" << endl << endl;
	for (const Client& Client : Clients) {
		if (Client.getMadeOrder()) {
			if (Client.getDiscountCard() && Client.getProfessional()) {
				cout << "������� �� ��'�: " << Client.getName() << " (���������� � ���������� �������)" << endl;
			}
			else if (!Client.getDiscountCard() && Client.getProfessional()) {
				cout << "������� �� ��'�: " << Client.getName() << " (���������� ��� ��������� ������)" << endl;
			}
			else if (Client.getDiscountCard() && !Client.getProfessional()) {
				cout << "������� �� ��'�: " << Client.getName() << " (�������� � ���������� �������)" << endl;
			}
			else {
				cout << "������� �� ��'�: " << Client.getName() << " (�������� ��� ��������� ������)" << endl;
			}
		}
	}
}
void print�lientListOfBranch(const PhotoCenter& photoCenter, int branchNumber)
{
	const vector<Client>& Clients = photoCenter.getClients();

	cout << "------------------------------------------------------------------------\n";
	cout << "������ �볺��� ��볿 �:" << branchNumber << endl;
	cout << "------------------------------------------------------------------------\n";
	cout << "�� ����� ������:" << endl << endl;
	for (const Client& Client : Clients) {
		if (Client.getBranch() == branchNumber){
			if (Client.getDiscountCard() && Client.getProfessional()) {
				cout << "������� �� ��'�: " << Client.getName() << " (���������� � ���������� �������)" << endl;
			}
			else if (!Client.getDiscountCard() && Client.getProfessional()) {
				cout << "������� �� ��'�: " << Client.getName() << " (���������� ��� ��������� ������)" << endl;
			}
			else if (Client.getDiscountCard() && !Client.getProfessional()) {
				cout << "������� �� ��'�: " << Client.getName() << " (�������� � ���������� �������)" << endl;
			}
		}
	}
	cout << "------------------------------------------------------------------------\n";
	cout << "�� ������� ���������� ������� ������:" << endl << endl;
	for (const Client& Client : Clients) {
		if (Client.getMadeOrder() && Client.getBranch() == branchNumber) {
			if (Client.getDiscountCard() && Client.getProfessional()) {
				cout << "������� �� ��'�: " << Client.getName() << " (���������� � ���������� �������)" << endl;
			}
			else if (!Client.getDiscountCard() && Client.getProfessional()) {
				cout << "������� �� ��'�: " << Client.getName() << " (���������� ��� ��������� ������)" << endl;
			}
			else if (Client.getDiscountCard() && !Client.getProfessional()) {
				cout << "������� �� ��'�: " << Client.getName() << " (�������� � ���������� �������)" << endl;
			}
			else {
				cout << "������� �� ��'�: " << Client.getName() << " (�������� ��� ��������� ������)" << endl;
			}
		}
	}
}

//���� ���� ������� � �������� ����������
void printPhotoCenterProfitFromSoldProducts(const PhotoCenter& photoCenter)
{
	int numOfFilms = 0, numOfCamaras = 0, numOfAlbums = 0;
	int pricePerFilm = 400,
		pricePerCamera = 16000 ,
		pricePerAlbum = 600;

	const vector<Product>& Products = photoCenter.getProducts();

	cout << "------------------------------------------------------------------------\n";
	cout << "���� ������� � �������� ���������� �������� ����� � ������ �� ���� ������:" << endl << endl;

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

	cout << "���������: " << numOfFilms * pricePerFilm << " ���." << endl << endl;

	cout << "�����������: " << numOfCamaras * pricePerCamera << " ���." << endl << endl;

	cout << "�������: " << numOfAlbums * pricePerAlbum << " ���." << endl << endl;

}
void printBranchProfitFromSoldProducts(const PhotoCenter& photoCenter, int branchNumber)
{
	int numOfFilms = 0, numOfCamaras = 0, numOfAlbums = 0;
	int pricePerFilm = 400,
		pricePerCamera = 16000,
		pricePerAlbum = 600;

	const vector<Product>& Products = photoCenter.getProducts();

	cout << "------------------------------------------------------------------------\n";
	cout << "���� ������� � �������� ���������� �������� ����� � ��볿 �: " << branchNumber << endl << endl;

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

	cout << "���������: " << numOfFilms * pricePerFilm << " ���." << endl << endl;

	cout << "�����������: " << numOfCamaras * pricePerCamera << " ���." << endl << endl;

	cout << "�������: " << numOfAlbums * pricePerAlbum << " ���." << endl << endl;
}

//������ ���������� � ����-���������, �� ������������ ��������� �������
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
	cout << "������ ���������� � ����-���������, �� ������������ ��������� ������� � ������ �� ���� ������:" << endl << endl;
	for (const Product& Product : Products) {
		if (Product.getNumOfFilms() == maxNum) {
			cout << "Գ���: " << Product.getName() << " |  ���������: " << Product.getNumOfFilms()<<" ��."<<endl;
		}
		else if (Product.getNumOfCamaras() == maxNum) {
			cout << "Գ���: " << Product.getName() << " |  �����������: " << Product.getNumOfCamaras() << " ��." << endl;
		}
		else if (Product.getNumOfAlbums() == maxNum) {
			cout << "Գ���: " << Product.getName() << " |  �������: " << Product.getNumOfAlbums() << " ��." << endl;
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
	cout << "������ ���������� � ����-���������, �� ������������ ��������� ������� � ��볿 �:" << branchNumber << endl << endl;
	for (const Product& Product : Products) {
		if (Product.getBranch() == branchNumber) {
			if (Product.getNumOfFilms() == maxNum) {
				cout << "Գ���: " << Product.getName() << " |  ���������: " << Product.getNumOfFilms() << " ��." << endl;
			}
			else if (Product.getNumOfCamaras() == maxNum) {
				cout << "Գ���: " << Product.getName() << " |  �����������: " << Product.getNumOfCamaras() << " ��." << endl;
			}
			else if (Product.getNumOfAlbums() == maxNum) {
				cout << "Գ���: " << Product.getName() << " |  �������: " << Product.getNumOfAlbums() << " ��." << endl;
			}
		}
	}
}

//������ �������� ����������
void printPhotoCenterSoldProducts(const PhotoCenter& photoCenter)
{
	int numOfFilms = 0, numOfCamaras = 0, numOfAlbums = 0;

	const vector<Product>& Products = photoCenter.getProducts();

	cout << "------------------------------------------------------------------------\n";
	cout << "������ �������� ���������� �������� ����� �� �� ������ � ������ �� ���� ������:" << endl << endl;

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

	cout << "���������: " << numOfFilms << " ��." << endl << endl;

	cout << "�����������: "<< numOfCamaras << " ��." << endl << endl;
	
	cout << "�������: "<< numOfAlbums << " ��." << endl << endl;
	
}
void printBranchSoldProducts(const PhotoCenter& photoCenter, int branchNumber)
{
	int numOfFilms = 0, numOfCamaras = 0, numOfAlbums = 0;

	const vector<Product>& Products = photoCenter.getProducts();

	cout << "------------------------------------------------------------------------\n";
	cout << "������ �������� ���������� �������� ����� �� �� ������ � ��볿 �: " << branchNumber << endl << endl;

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

	cout << "���������: " << numOfFilms << " ��." << endl << endl;

	cout << "�����������: " << numOfCamaras << " ��." << endl << endl;

	cout << "�������: " << numOfAlbums << " ��." << endl << endl;

}

//������ ������� ����
void printListOfWorkers(const PhotoCenter& photoCenter)
{
	const vector<Worker>& Workers = photoCenter.getWorkers();

	cout << "------------------------------------------------------------------------\n";
	cout << "������ ������� ���� � ������ �� ���� ������:" << endl;
	
	cout << "------------------------------------------------------------------------\n";
	cout << "�������� ����������" << endl;
	for (const Worker& Worker : Workers) {
		if (Worker.getPost() == "�������� ����������") {
			cout << "������� �� ��'�: " << Worker.getName() << endl;
		}
	}
	
	cout << "------------------------------------------------------------------------\n";
	cout << "��������� �������:" << endl << endl;
	for (const Worker& Worker : Workers) {
		if (Worker.getPost() == "�������� ��������") {
			if (Worker.getBranch() != NULL) {
				cout << "������� �� ��'�: " << Worker.getName() << " |  ��������� ��볿 �" << Worker.getBranch() << endl;
			}
			else if (Worker.getKiosk() != NULL) {
				cout << "������� �� ��'�: " << Worker.getName() << " |  ��������� ����� �" << Worker.getKiosk() << endl;
			}
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "��������� ������� ���������: " << endl << endl;
	for (const Worker& Worker : Workers) {
		if (Worker.getPost() == "�������� ������� ���������") {
			if (Worker.getBranch() != NULL) {
				cout << "������� �� ��'�: " << Worker.getName() << " |  ��������� ��볿 �" << Worker.getBranch() << endl;
			}
			else if (Worker.getKiosk() != NULL) {
				cout << "������� �� ��'�: " << Worker.getName() << " |  ��������� ����� �" << Worker.getKiosk() << endl;
			}
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "��������� ��������: " << endl << endl;
	for (const Worker& Worker : Workers) {
		if (Worker.getPost() == "�������� ��������") {
			if (Worker.getBranch() != NULL) {
				cout << "������� �� ��'�: " << Worker.getName() << " |  ��������� ��볿 �" << Worker.getBranch() << endl;
			}
			else if (Worker.getKiosk() != NULL) {
				cout << "������� �� ��'�: " << Worker.getName() << " |  ��������� ����� �" << Worker.getKiosk() << endl;
			}
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "������ (���������� �� ���� ����������): " << endl << endl;
	for (const Worker& Worker : Workers) {
		if (Worker.getPost() == "������") {
			if (Worker.getBranch() != NULL) {
				cout << "������� �� ��'�: " << Worker.getName() << " |  ��������� ��볿 �" << Worker.getBranch() << endl;
			}
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "������������� (���������� �� ���������� ���������): " << endl << endl;
	for (const Worker& Worker : Workers) {
		if (Worker.getPost() == "������������") {
			if (Worker.getBranch() != NULL) {
				cout << "������� �� ��'�: " << Worker.getName() << " |  ��������� ��볿 �" << Worker.getBranch() << endl;
			}
		}
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "�������� ����������: " << endl << endl;
	for (const Worker& Worker : Workers) {
		if (Worker.getPost() == "��������� ����������") {
			if (Worker.getBranch() != NULL) {
				cout << "������� �� ��'�: " << Worker.getName() << " |  ��������� ��볿 �" << Worker.getBranch() << endl;
			}
			else if (Worker.getKiosk() != NULL) {
				cout << "������� �� ��'�: " << Worker.getName() << " |  ��������� ����� �" << Worker.getKiosk() << endl;
			}
		}
	}
}
void printListOfPost(const PhotoCenter& photoCenter)
{
	const vector<Worker>& Workers = photoCenter.getWorkers();
	int choice;
	cout << "------------------------------------------------------------------------\n";
	cout << "�������� ������ ������� ���� �� �����:" << endl
		<< "1. �������� ����������" << endl
		<< "2. �������� ��������" << endl
		<< "3. �������� ������� ���������" << endl
		<< "4. �������� ��������" << endl
		<< "5. ������" << endl
		<< "6. ������������" << endl
		<< "7. ��������� ����������" << endl;
	cin >> choice;

	cout << "------------------------------------------------------------------------\n";
	cout << "������ ������� ���� �� ����������� �������:" << endl;
	if (choice == 1) {
		cout << "------------------------------------------------------------------------\n";
		cout << "�������� ����������" << endl;
		for (const Worker& Worker : Workers) {
			if (Worker.getPost() == "�������� ����������") {
				cout << "������� �� ��'�: " << Worker.getName() << endl;
			}
		}
	}
	else if (choice == 2) {
		cout << "------------------------------------------------------------------------\n";
		cout << "��������� �������:" << endl << endl;
		for (const Worker& Worker : Workers) {
			if (Worker.getPost() == "�������� ��������") {
				if (Worker.getBranch() != NULL) {
					cout << "������� �� ��'�: " << Worker.getName() << " |  ��������� ��볿 �" << Worker.getBranch() << endl;
				}
				else if (Worker.getKiosk() != NULL) {
					cout << "������� �� ��'�: " << Worker.getName() << " |  ��������� ����� �" << Worker.getKiosk() << endl;
				}
			}
		}
	}
	else if (choice == 3) {
		cout << "------------------------------------------------------------------------\n";
		cout << "��������� ������� ���������: " << endl << endl;
		for (const Worker& Worker : Workers) {
			if (Worker.getPost() == "�������� ������� ���������") {
				if (Worker.getBranch() != NULL) {
					cout << "������� �� ��'�: " << Worker.getName() << " |  ��������� ��볿 �" << Worker.getBranch() << endl;
				}
				else if (Worker.getKiosk() != NULL) {
					cout << "������� �� ��'�: " << Worker.getName() << " |  ��������� ����� �" << Worker.getKiosk() << endl;
				}
			}
		}
	}
	else if (choice == 4) {
		cout << "------------------------------------------------------------------------\n";
		cout << "��������� ��������: " << endl << endl;
		for (const Worker& Worker : Workers) {
			if (Worker.getPost() == "�������� ��������") {
				if (Worker.getBranch() != NULL) {
					cout << "������� �� ��'�: " << Worker.getName() << " |  ��������� ��볿 �" << Worker.getBranch() << endl;
				}
				else if (Worker.getKiosk() != NULL) {
					cout << "������� �� ��'�: " << Worker.getName() << " |  ��������� ����� �" << Worker.getKiosk() << endl;
				}
			}
		}
	}
	else if (choice == 5) {
		cout << "------------------------------------------------------------------------\n";
		cout << "������ (���������� �� ���� ����������): " << endl << endl;
		for (const Worker& Worker : Workers) {
			if (Worker.getPost() == "������") {
				if (Worker.getBranch() != NULL) {
					cout << "������� �� ��'�: " << Worker.getName() << " |  ��������� ��볿 �" << Worker.getBranch() << endl;
				}
			}
		}
	}
	else if (choice == 6) {
		cout << "------------------------------------------------------------------------\n";
		cout << "������������� (���������� �� ���������� ���������): " << endl << endl;
		for (const Worker& Worker : Workers) {
			if (Worker.getPost() == "������������") {
				if (Worker.getBranch() != NULL) {
					cout << "������� �� ��'�: " << Worker.getName() << " |  ��������� ��볿 �" << Worker.getBranch() << endl;
				}
			}
		}
	}
	else if (choice == 7) {
		cout << "------------------------------------------------------------------------\n";
		cout << "�������� ����������: " << endl << endl;
		for (const Worker& Worker : Workers) {
			if (Worker.getPost() == "��������� ����������") {
				if (Worker.getBranch() != NULL) {
					cout << "������� �� ��'�: " << Worker.getName() << " |  ��������� ��볿 �" << Worker.getBranch() << endl;
				}
				else if (Worker.getKiosk() != NULL) {
					cout << "������� �� ��'�: " << Worker.getName() << " |  ��������� ����� �" << Worker.getKiosk() << endl;
				}
			}
		}
	}
}