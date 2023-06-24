#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>

using namespace std;

// ���� Գ��
class Branch {
private:
	int n;
	string address;
	// �������� ���������� � ������

public:
	Branch(int n, const string& address)
		: n(n), address(address) {}
	int getBranchNum() const { return n; }
	string getAddress() const { return address; }
};
// ���� ʳ���
class Kiosk {
private:
	int n;
	string address;
	int attachedBranch;
	// �������� ���������� � ������

public:
	Kiosk(int n, const string& address, int attachedBranch)
		: n(n), address(address), attachedBranch(attachedBranch) {}

	int getKioskNum() const { return n; }
	string getAddress() const { return address; }
	int getAttachedBranch() const { return attachedBranch; }
};

// ���� ���������
class Worker
{
private:
	string name, post;
	int branch, kiosk;

public:
	Worker(string name, string post, int branch, int kiosk)
		: name(name), post(post), branch(branch), kiosk(kiosk) {}

	string getName() const { return name; }
	string getPost() const { return post; }
	int getBranch() const{ return branch; }
	int getKiosk() const{ return kiosk; }
};

// ����� ���������
class OrderForPrint {
private:
	int numPhotosPF, numPhotos;
	string paperType, format;
	bool express;
	int branch;
	int kiosk;
	// �������� ���������� � ������

public:
	OrderForPrint(int numPhotosPF, int numPhotos, string paperType, string format, bool express, int branch, int kiosk)
		: numPhotosPF(numPhotosPF), numPhotos(numPhotos), paperType(paperType), format(format), express(express), branch(branch), kiosk(kiosk) {}

	// ������ ��� ���������� �������, ��������� ������ �� ����
	int getNumPhotosPF() const { return numPhotosPF; }
	int getNumPhotos() const { return numPhotos; }
	string getPaperType() const { return paperType; }
	string getFormat() const { return format; }
	bool getExpress() const { return express; }
	int getBranch() const { return branch; }
	int getKiosk() const { return kiosk; }
};
class OrderForDevelopment
{
private:
	int numFilms;
	bool express, boughtHere;
	int branch;
	int kiosk;
public:
	OrderForDevelopment(int numFilms, bool express, bool boughtHere, int branch, int kiosk)
		: numFilms(numFilms), express(express), boughtHere(boughtHere), branch(branch), kiosk(kiosk) {}

	int getNumFilms() const { return numFilms; }
	bool getExpress() const { return express; }
	bool getBoughtHere() const { return boughtHere; }
	int getBranch() const { return branch; }
	int getKiosk() const { return kiosk; }
};
class CombinedOrder
{
private:
	int numPhotosPF, numPhotos;
	string paperType, format;
	int numFilms;
	bool express, boughtHere;
	int branch;
	int kiosk;
public:
	CombinedOrder(int numPhotosPF, int numPhotos, string paperType, string format, int numFilms, bool express, bool boughtHere, int branch, int kiosk)
		: numPhotosPF(numPhotosPF), numPhotos(numPhotos), paperType(paperType), format(format), numFilms(numFilms), express(express), boughtHere(boughtHere), branch(branch), kiosk(kiosk) {}
	
	int getNumPhotosPF() const { return numPhotosPF; }
	int getNumPhotos() const { return numPhotos; }
	string getPaperType() const { return paperType; }
	string getFormat() const { return format; }
	int getNumFilms() const { return numFilms; }
	bool getExpress() const { return express; }
	bool getBoughtHere() const { return boughtHere; }
	int getBranch() const { return branch; }
	int getKiosk() const { return kiosk; }
};
class Orders 
{
private:
	vector<OrderForPrint> OrdersForPrint;
	vector<OrderForDevelopment> OrdersForDevelopment;
	vector<CombinedOrder> CombinedOrders;
public:
	void addOrderForPrint(const OrderForPrint& orderForPrint) { OrdersForPrint.push_back(orderForPrint); }
	void addOrderForDevelopment(const OrderForDevelopment& orderForDevelopment) { OrdersForDevelopment.push_back(orderForDevelopment); }
	void addCombinedOrder(const CombinedOrder& combinedOrder) { CombinedOrders.push_back(combinedOrder); }

	vector<OrderForPrint> getOrdersForPrint() const { return OrdersForPrint; }
	vector<OrderForDevelopment> getOrdersForDevelopment() const { return OrdersForDevelopment; }
	vector<CombinedOrder> getCombinedOrders() const { return CombinedOrders; }
};

//���� ������� � ������� ���������
class RevenueFromSimpleOrders
{
private:
	float revenueFromPrint, revenueFromDevelop, revenueFromCombined;

public:
	RevenueFromSimpleOrders(float revenueFromPrint, float revenueFromDevelop, float revenueFromCombined)
		: revenueFromPrint(revenueFromPrint), revenueFromDevelop(revenueFromDevelop), revenueFromCombined(revenueFromCombined) {}

	float getRevenueFromPrint() const { return revenueFromPrint; }
	float getRevenueFromDevelop() const { return revenueFromDevelop; }
	float getRevenueFromCombined() const { return revenueFromCombined; }
};
//���� ������� � ��������� ���������
class RevenueFromExpressOrders
{
private:
	float revenueFromPrint, revenueFromDevelop, revenueFromCombined,
		revenueFromPrintExpress, revenueFromDevelopExpress, revenueFromCombinedExpress;

public:
	RevenueFromExpressOrders(float revenueFromPrint, float revenueFromDevelop, float revenueFromCombined, float revenueFromPrintExpress, float revenueFromDevelopExpress, float revenueFromCombinedExpress)
		: revenueFromPrint(revenueFromPrint), revenueFromDevelop(revenueFromDevelop), revenueFromCombined(revenueFromCombined), revenueFromPrintExpress(revenueFromPrintExpress), revenueFromDevelopExpress(revenueFromDevelopExpress), revenueFromCombinedExpress(revenueFromCombinedExpress) {}
	
	float getRevenueFromPrint() const{ return revenueFromPrint; }
	float getRevenueFromDevelop() const{ return revenueFromDevelop; }
	float getRevenueFromCombined() const{ return revenueFromCombined; }
	float getRevenueFromPrintExpress() const{ return revenueFromPrintExpress; }
	float getRevenueFromDevelopExpress() const{ return revenueFromDevelopExpress; }
	float getRevenueFromCombinedExpress() const{ return revenueFromCombinedExpress; }
}; 
class Revenue
{
private:
	vector<RevenueFromSimpleOrders> RevenueFromSimpleOrders_;
	vector<RevenueFromExpressOrders> RevenueFromExpressOrders_;
public:
	void addRevenueFromSimpleOrders(const RevenueFromSimpleOrders& revenueFromSimpleOrders) { RevenueFromSimpleOrders_.push_back(revenueFromSimpleOrders); }
	void addRevenueFromExpressOrders(const RevenueFromExpressOrders& revenueFromExpressOrders) { RevenueFromExpressOrders_.push_back(revenueFromExpressOrders); }

	vector<RevenueFromSimpleOrders> getRevenueFromSimpleOrders_() const { return RevenueFromSimpleOrders_; }
	vector<RevenueFromExpressOrders> getRevenueFromExpressOrders_() const { return RevenueFromExpressOrders_; }
};

// ���� �볺��
class Client {
private:
	string name;
	bool discountCard, professional, madeOrder;
	int branch;

public:
	Client(string name, bool discountCard, bool professional, bool madeOrder, int branch)
		: name(name), discountCard(discountCard), professional(professional), madeOrder(madeOrder), branch(branch) {}
	
	string getName() const { return name; }
	bool getDiscountCard() const { return discountCard; }
	bool getProfessional() const { return professional; }
	bool getMadeOrder() const { return madeOrder; }
	int getBranch() const { return branch; }
};

// ���� �������
class Product {
private:
	int num;
	string name;
	bool films, cameras, albums;
	int numOfFilms, numOfCamaras, numOfAlbums, branch;
public:
	Product(int num, string name, bool films, bool cameras, bool albums, int numOfFilms, int numOfCamaras, int numOfAlbums, int branch)
		: num(num), name(name), films(films), cameras(cameras), albums(albums), numOfFilms(numOfFilms), numOfCamaras(numOfCamaras), numOfAlbums(numOfAlbums), branch(branch) {}
	
	int getNum() const { return num; }
	string getName() const { return name; }
	bool getFilms() const { return films; }
	bool getCameras() const { return cameras; }
	bool getAlbums() const { return albums; }
	int getNumOfFilms() const { return numOfFilms; }
	int getNumOfCamaras() const { return numOfCamaras; }
	int getNumOfAlbums() const { return numOfAlbums; }
	int getBranch() const { return branch; }
};

// ���� ������������
class Supplier {
private:
	int num;
	string name;
	bool films, cameras, albums;
	int numOfFilms, numOfCamaras, numOfAlbums;

public:
	Supplier(int num, string name, bool films, bool cameras, bool albums, int numOfFilms, int numOfCamaras, int numOfAlbums)
		: num(num),name(name), films(films), cameras(cameras), albums(albums), numOfFilms(numOfFilms), numOfCamaras(numOfCamaras), numOfAlbums(numOfAlbums) {}

	int getNum() const { return num; }
	string getName() const { return name; }
	bool getFilms() const { return films; }
	bool getCameras() const { return cameras; }
	bool getAlbums() const { return albums; }
	int getNumOfFilms() const { return numOfFilms; }
	int getNumOfCamaras() const { return numOfCamaras; }
	int getNumOfAlbums() const { return numOfAlbums; }
};

// ���� ���������
class PhotoCenter {
private:
	vector<Branch> branches;
	vector<Kiosk> kiosks;
	vector<Supplier> suppliers;
	vector<Product> products;
	vector<Client> clients;
	vector<Worker> workers;
 
public:
	void addBranch(const Branch& branch) { branches.push_back(branch); }
	void addKiosk(const Kiosk& kiosk) { kiosks.push_back(kiosk); }
	void addSupplier(const Supplier& supplier) { suppliers.push_back(supplier); }
	void addProduct(const Product& product) { products.push_back(product); }
	void addClient(const Client& client) { clients.push_back(client); }
	void addWorker(const Worker& worker) { workers.push_back(worker); }

	vector<Branch> getBranches() const { return branches; }
	vector<Kiosk> getKiosks() const { return kiosks; }
	vector<Supplier> getSuppliers() const { return suppliers; }
	vector<Product> getProducts() const { return products; }
	vector<Client> getClients() const { return clients; }
	vector<Worker> getWorkers() const { return workers; }
};


//������� ��� ��������� �����
void createData(PhotoCenter& photoCenter, Orders& orders);
//���������� ���� �������
void branchProfitFromOrders�alc(const Orders& orders, Revenue& revenue, int branchNumber);
void kioskProfitFromOrders�alc(const Orders& orders, Revenue& revenue, int kioskNumber);

//������ ���� �� �����
void printBranchesAndKiosks(const PhotoCenter& photoCenter);
//������ ��� ���������
void printOrders(const Orders& orders);
//������ ��� ��������� (������ ������� �� ���������)
void printOrdersForBranchByNumber(const Orders& orders, int branchNumber);
void printOrdersForKioskByNumber(const Orders& orders, int kioskNumber);
//���� ���� �������
void printBranchProfitFromOrders(const Orders& orders, const Revenue& revenue, int branchNumber);
void printKioskProfitFromOrders(const Orders& orders, const Revenue& revenue, int kioskNumber);
//���� ������� ������������ ����������
void printBranchNumOfPhotos(const Orders& orders, int branchNumber);
void printKioskNumOfPhotos(const Orders& orders, int kioskNumber);
//���� ������� ���������� ���������
void printBranchNumOfFilms(const Orders& orders, int branchNumber);
void printKioskNumOfFilms(const Orders& orders, int kioskNumber);
//���� ������� ��������
void printSuppliers(const PhotoCenter& photoCenter);
//������ �볺���
void print�lientListOfPhotoCenter(const PhotoCenter& photoCenter);
void print�lientListOfBranch(const PhotoCenter& photoCenter, int branchNumber);
//���� ���� ������� � �������� ����������
void printPhotoCenterProfitFromSoldProducts(const PhotoCenter& photoCenter);
void printBranchProfitFromSoldProducts(const PhotoCenter& photoCenter, int branchNumber);
//������ ���������� � ����-���������, �� ������������ ��������� �������
void printTopPhotoCenterSoldProducts(const PhotoCenter& photoCenter);
void printTopBranchSoldProducts(const PhotoCenter& photoCenter, int branchNumber);
//������ �������� ����������
void printPhotoCenterSoldProducts(const PhotoCenter& photoCenter);
void printBranchSoldProducts(const PhotoCenter& photoCenter, int branchNumber);
//������ ������� ����
void printListOfWorkers(const PhotoCenter& photoCenter);
void printListOfPost(const PhotoCenter& photoCenter);