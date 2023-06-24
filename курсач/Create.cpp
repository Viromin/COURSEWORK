#include "Data.h"

void createData(PhotoCenter& photoCenter, Orders& orders)
{
	//----------------------------------------------------------------------------------
	Branch branch1(1, "Адреса філії 1");
	Branch branch2(2, "Адреса філії 2");
	Branch branch3(3, "Адреса філії 3");
	Kiosk kiosk1(1, "Адреса кіоска 1", 1);
	Kiosk kiosk2(2, "Адреса кіоска 2", 1);
	Kiosk kiosk3(3, "Адреса кіоска 3", 2);
	Kiosk kiosk4(4, "Адреса кіоска 4", 3);
	//----------------------------------------------------------------------------------
	OrderForPrint orderFP1(25, 225, "Глянцевий", "30x45", true, 1, NULL);
	OrderForPrint orderFP2(45, 135, "Глянцевий", "10x15", true, 1, NULL);
	OrderForPrint orderFP3(4, 92, "Матовий", "15x21", false, 1, NULL);
	OrderForPrint orderFP4(2, 174, "Матовий", "21x30", false, 1, NULL);
	OrderForPrint orderFP5(3, 243, "Матовий", "15x21", false, 1, NULL);

	OrderForPrint orderFP6(15, 75, "Глянцевий", "15x21", true, 2, NULL);
	OrderForPrint orderFP7(75, 300, "Матовий", "30x45", true, 2, NULL);
	OrderForPrint orderFP8(4, 176, "Глянцевий", "30x45", true, 2, NULL);
	OrderForPrint orderFP9(2, 64, "Матовий", "10x15", false, 2, NULL);
	OrderForPrint orderFP10(1, 234, "Матовий", "21x30", false, 2, NULL);
	OrderForPrint orderFP11(5, 195, "Глянцевий", "15x21", false, 2, NULL);

	OrderForPrint orderFP12(7, 203, "Глянцевий", "30x45", true, 3, NULL);
	OrderForPrint orderFP13(4, 156, "Матовий", "10x15", true, 3, NULL);
	OrderForPrint orderFP14(3, 252, "Матовий", "15x21", true, 3, NULL);
	OrderForPrint orderFP15(6, 180, "Глянцевий", "10x15", false, 3, NULL);
	OrderForPrint orderFP16(4, 84, "Матовий", "21x30", false, 3, NULL);
	OrderForPrint orderFP17(30, 240, "Глянцевий", "15x21", false, 3, NULL);
	OrderForPrint orderFP18(2, 96, "Глянцевий", "21x30", false, 3, NULL);

	OrderForPrint orderFP19(5, 70, "Глянцевий", "15x21", false, NULL, 1);
	OrderForPrint orderFP20(3, 93, "Матовий", "21x30", false, NULL, 1);
	OrderForPrint orderFP21(4, 116, "Глянцевий", "10x15", false, NULL, 1);
	OrderForPrint orderFP22(2, 52, "Глянцевий", "10x15", false, NULL, 1);

	OrderForPrint orderFP23(3, 111, "Глянцевий", "15x21", false, NULL, 2);
	OrderForPrint orderFP24(2, 68, "Глянцевий", "21x30", false, NULL, 2);
	OrderForPrint orderFP25(1, 82, "Матовий", "10x15", false, NULL, 2);
	OrderForPrint orderFP26(4, 192, "Матовий", "15x21", false, NULL, 2);
	OrderForPrint orderFP27(3, 234, "Глянцевий", "10x15", false, NULL, 2);

	OrderForPrint orderFP28(3, 78, "Глянцевий", "21x30", false, NULL, 3);
	OrderForPrint orderFP29(4, 88, "Матовий", "10x15", false, NULL, 3);
	OrderForPrint orderFP30(1, 178, "Матовий", "15x21", false, NULL, 3);

	OrderForPrint orderFP31(2, 112, "Глянцевий", "15x21", false, NULL, 4);
	OrderForPrint orderFP32(5, 75, "Глянцевий", "15x21", false, NULL, 4);
	OrderForPrint orderFP33(15, 45, "Матовий", "21x30", false, NULL, 4);

	OrderForDevelopment orderFD1(3, true, false, 1, NULL);
	OrderForDevelopment orderFD2(2, true, true, 1, NULL);
	OrderForDevelopment orderFD3(4, false, false, 1, NULL);
	OrderForDevelopment orderFD4(5, false, false, 1, NULL);

	OrderForDevelopment orderFD5(1, true, false, 2, NULL);
	OrderForDevelopment orderFD6(3, true, true, 2, NULL);
	OrderForDevelopment orderFD7(2, true, false, 2, NULL);
	OrderForDevelopment orderFD8(4, false, false, 2, NULL);
	OrderForDevelopment orderFD9(2, false, false, 2, NULL);

	OrderForDevelopment orderFD10(4, true, false, 3, NULL);
	OrderForDevelopment orderFD11(3, false, false, 3, NULL);
	OrderForDevelopment orderFD12(1, false, false, 3, NULL);

	OrderForDevelopment orderFD13(3, false, false, NULL, 1);
	OrderForDevelopment orderFD14(1, false, false, NULL, 1);

	OrderForDevelopment orderFD15(2, false, false, NULL, 2);
	OrderForDevelopment orderFD16(6, false, false, NULL, 2);
	OrderForDevelopment orderFD17(3, false, false, NULL, 2);

	OrderForDevelopment orderFD18(4, false, false, NULL, 3);
	OrderForDevelopment orderFD19(2, false, false, NULL, 3);

	OrderForDevelopment orderFD20(5, false, false, NULL, 4);
	OrderForDevelopment orderFD21(6, false, false, NULL, 4);
	OrderForDevelopment orderFD22(2, false, false, NULL, 4);

	CombinedOrder cOrder1(3, 69, "Матовий", "10x15", 2, true, false, 1, NULL);
	CombinedOrder cOrder2(4, 72, "Глянцевий", "15x21", 3, true, false, 1, NULL);
	CombinedOrder cOrder3(2, 154, "Глянцевий", "21x30", 5, false, false, 1, NULL);

	CombinedOrder cOrder4(2, 84, "Матовий", "10x15", 2, true, false, 2, NULL);
	CombinedOrder cOrder5(5, 145, "Глянцевий", "15x21", 4, true, false, 2, NULL);
	CombinedOrder cOrder6(3, 192, "Глянцевий", "10x15", 3, false, true, 2, NULL);
	CombinedOrder cOrder7(4, 132, "Матовий", "21x30", 6, false, false, 2, NULL);

	CombinedOrder cOrder8(13, 234, "Глянцевий", "10x15", 4, true, false, 3, NULL);
	CombinedOrder cOrder9(9, 63, "Матовий", "21x30", 2, false, false, 3, NULL);
	CombinedOrder cOrder10(3, 144, "Матовий", "15x21", 5, false, true, 3, NULL);
	CombinedOrder cOrder11(6, 216, "Глянцевий", "21x30", 1, false, false, 3, NULL);

	CombinedOrder cOrder12(7, 168, "Глянцевий", "15x21", 5, false, false, NULL, 1);
	CombinedOrder cOrder13(3, 231, "Матовий", "10x15", 2, false, false, NULL, 1);
	CombinedOrder cOrder14(6, 156, "Глянцевий", "10x15", 4, false, false, NULL, 1);

	CombinedOrder cOrder15(5, 75, "Матовий", "10x15", 3, false, false, NULL, 2);
	CombinedOrder cOrder16(3, 252, "Глянцевий", "15x21", 3, false, false, NULL, 2);
	CombinedOrder cOrder17(4, 296, "Глянцевий", "21x30", 3, false, false, NULL, 2);

	CombinedOrder cOrder18(3, 93, "Матовий", "21x30", 1, false, false, NULL, 3);
	CombinedOrder cOrder19(4, 240, "Глянцевий", "10x15", 4, false, false, NULL, 3);

	CombinedOrder cOrder20(3, 156, "Матовий", "10x15", 3, false, false, NULL, 4);
	CombinedOrder cOrder21(2, 142, "Матовий", "15x21", 1, false, false, NULL, 4);
	CombinedOrder cOrder22(4, 96, "Глянцевий", "15x21", 2, false, false, NULL, 4);
	//----------------------------------------------------------------------------------
	Supplier supplier1(1, "Фірма-виробник №1", false, true, true, NULL, 45, 150);
	Supplier supplier2(2, "Фірма-виробник №2", true, false, false, 130, NULL, NULL);
	Supplier supplier3(3, "Фірма-виробник №1", true, true, false, 125, 30, NULL);
	Supplier supplier4(4, "Фірма-виробник №3", true, false, true, 160, NULL, 100);
	Supplier supplier5(5, "Фірма-виробник №2", false, true, false, NULL, 55, NULL);
	Supplier supplier6(6, "Фірма-виробник №4", false, true, true, NULL, 25, 125);
	Supplier supplier7(7, "Фірма-виробник №3", true, true, true, 110, 75, 90);
	//----------------------------------------------------------------------------------
	Product product1(1, "Фірма-виробник №1", true, false, false, 77, NULL, NULL, 2);
	Product product2(2, "Фірма-виробник №2", true, false, false, 84, NULL, NULL, 3);
	Product product3(3, "Фірма-виробник №1", true, false, false, 43, NULL, NULL, 1);
	Product product4(4, "Фірма-виробник №3", false, true, false, NULL, 34, NULL, 1);
	Product product5(5, "Фірма-виробник №2", false, true, false, NULL, 31, NULL, 2);
	Product product6(6, "Фірма-виробник №4", false, true, false, NULL, 21, NULL, 3);
	Product product7(7, "Фірма-виробник №3", false, false, true, NULL, NULL, 54, 2);
	Product product8(8, "Фірма-виробник №4", false, false, true, NULL, NULL, 48, 1);
	Product product9(9, "Фірма-виробник №1", false, false, true, NULL, NULL, 84, 3);
	Product product10(10, "Фірма-виробник №2", false, true, false, NULL, 23, NULL, 3);
	Product product11(11, "Фірма-виробник №3", false, false, true, NULL, NULL, 21, 1);
	//----------------------------------------------------------------------------------
	Client client1("Януш Дмитро", true, false, false, 2);
	Client client2("Голубка Олександр", true, true, false, 3);
	Client client3("Яна Цист", false, true, true, 1);
	Client client4("Повар Дмитро", false, false, true, 2);
	Client client5("Сушко Вероніка", false, false, false, 2);
	Client client6("Фриз Сергій", true, false, true, 3);
	Client client7("Пелехович Андрій", false, true, false, 1);
	Client client8("Коваль Юра", true, true, true, 1);
	Client client9("Якимів Тетяна", false, true, false, 3);
	Client client10("Сенькович Роман", true, false, true, 3);
	Client client11("Мацишин Назар", true, false, true, 2);
	Client client12("Курт Кобейн", false, true, false, 3);
	Client client13("Хмельницький Богдан", false, true, true, 1);
	Client client14("Сіріус Снейк", true, false, false, 2);
	Client client15("Херінстон Білі", false, true, true, 2);
	Client client16("Паркер Пітер", true, false, false, 1);
	//----------------------------------------------------------------------------------
	Worker worker0("Івко Ангеліна", "Директор фотоцентру", NULL, NULL);
	
	Worker worker1("Міщук Йосип", "Менеджер відділення", 1, NULL);
	Worker worker2("Синицький Ілля", "Менеджер прийому замовлень", 1, NULL);
	Worker worker3("Циганик Влада", "Менеджер поставок", 1, NULL);
	Worker worker4("Бутейко Євгеній", "Друкар", 1, NULL);
	Worker worker5("Міщук Олег", "Друкар", 1, NULL);
	Worker worker6("Іванусів Віталій", "Фотолаборант", 1, NULL);
	Worker worker7("Чишко Наталія", "Фотолаборант", 1, NULL);
	Worker worker8("Зорін Антон", "Продавець фототоварів", 1, NULL);

	Worker worker9("Мицик Уляна", "Менеджер відділення", 2, NULL);
	Worker worker10("Вербіцький Роман", "Менеджер прийому замовлень", 2, NULL);
	Worker worker11("Максимчук Максим", "Менеджер поставок", 2, NULL);
	Worker worker12("Сидорук Віктор", "Друкар", 2, NULL);
	Worker worker13("Мащенко Сергій", "Друкар", 2, NULL);
	Worker worker14("Корбан Артем", "Фотолаборант", 2, NULL);
	Worker worker15("Кльоц Олена", "Фотолаборант", 2, NULL);
	Worker worker16("Підлужний Богдан", "Продавець фототоварів", 2, NULL);

	Worker worker17("Костюк Дмитро", "Менеджер відділення", 3, NULL);
	Worker worker18("Ленкевич Діана", "Менеджер прийому замовлень", 3, NULL);
	Worker worker19("Білай Зоряна", "Менеджер поставок", 3, NULL);
	Worker worker20("Цибуленко Андрій", "Друкар", 3, NULL);
	Worker worker21("Дощенко Святослав", "Друкар", 3, NULL);
	Worker worker22("Шашкевич Люба", "Фотолаборант", 3, NULL);
	Worker worker23("Мацкевич Віталій", "Фотолаборант", 3, NULL);
	Worker worker24("Лущик Ігор", "Продавець фототоварів", 3, NULL);

	Worker worker25("Горянський Назар", "Менеджер відділення", NULL, 1);
	Worker worker26("Равлюк Тарас", "Менеджер прийому замовлень", NULL, 1);
	Worker worker27("Потульницький Віктор", "Менеджер поставок", NULL, 1);
	Worker worker28("Болюх Оксана", "Продавець фототоварів", NULL, 1);

	Worker worker29("Доманицький Денис", "Менеджер відділення", NULL, 2);
	Worker worker30("Данилів Роман", "Менеджер прийому замовлень", NULL, 2);
	Worker worker31("Гоменюк Катерина", "Менеджер поставок", NULL, 2);
	Worker worker32("Мурашко Максим", "Продавець фототоварів", NULL, 2);

	Worker worker33("Лопушанський Володимир", "Менеджер відділення", NULL, 3);
	Worker worker34("Павлик Вероніка", "Менеджер прийому замовлень", NULL, 3);
	Worker worker35("Загнітко Ольга", "Менеджер поставок", NULL, 3);
	Worker worker36("Соколенко Іван", "Продавець фототоварів", NULL, 3);

	Worker worker37("Горбачук Ярослав", "Менеджер відділення", NULL, 4);
	Worker worker38("Загацька Ірина", "Менеджер прийому замовлень", NULL, 4);
	Worker worker39("Химич Ілля", "Менеджер поставок", NULL, 4);
	Worker worker40("Вербіцький Сергій", "Продавець фототоварів", NULL, 4);
	//----------------------------------------------------------------------------------
	photoCenter.addBranch(branch1);
	photoCenter.addBranch(branch2);
	photoCenter.addBranch(branch3);
	photoCenter.addKiosk(kiosk1);
	photoCenter.addKiosk(kiosk2);
	photoCenter.addKiosk(kiosk3);
	photoCenter.addKiosk(kiosk4);

	orders.addOrderForPrint(orderFP1);
	orders.addOrderForPrint(orderFP2);
	orders.addOrderForPrint(orderFP3);
	orders.addOrderForPrint(orderFP4);
	orders.addOrderForPrint(orderFP5);
	orders.addOrderForPrint(orderFP6);
	orders.addOrderForPrint(orderFP7);
	orders.addOrderForPrint(orderFP8);
	orders.addOrderForPrint(orderFP9);
	orders.addOrderForPrint(orderFP10);
	orders.addOrderForPrint(orderFP11);
	orders.addOrderForPrint(orderFP12);
	orders.addOrderForPrint(orderFP13);
	orders.addOrderForPrint(orderFP14);
	orders.addOrderForPrint(orderFP15);
	orders.addOrderForPrint(orderFP16);
	orders.addOrderForPrint(orderFP17);
	orders.addOrderForPrint(orderFP18);
	orders.addOrderForPrint(orderFP19);
	orders.addOrderForPrint(orderFP20);
	orders.addOrderForPrint(orderFP21);
	orders.addOrderForPrint(orderFP22);
	orders.addOrderForPrint(orderFP23);
	orders.addOrderForPrint(orderFP24);
	orders.addOrderForPrint(orderFP25);
	orders.addOrderForPrint(orderFP26);
	orders.addOrderForPrint(orderFP27);
	orders.addOrderForPrint(orderFP28);
	orders.addOrderForPrint(orderFP29);
	orders.addOrderForPrint(orderFP30);
	orders.addOrderForPrint(orderFP31);
	orders.addOrderForPrint(orderFP32);
	orders.addOrderForPrint(orderFP33);
	orders.addOrderForDevelopment(orderFD1);
	orders.addOrderForDevelopment(orderFD2);
	orders.addOrderForDevelopment(orderFD3);
	orders.addOrderForDevelopment(orderFD4);
	orders.addOrderForDevelopment(orderFD5);
	orders.addOrderForDevelopment(orderFD6);
	orders.addOrderForDevelopment(orderFD7);
	orders.addOrderForDevelopment(orderFD8);
	orders.addOrderForDevelopment(orderFD9);
	orders.addOrderForDevelopment(orderFD10);
	orders.addOrderForDevelopment(orderFD11);
	orders.addOrderForDevelopment(orderFD12);
	orders.addOrderForDevelopment(orderFD13);
	orders.addOrderForDevelopment(orderFD14);
	orders.addOrderForDevelopment(orderFD15);
	orders.addOrderForDevelopment(orderFD16);
	orders.addOrderForDevelopment(orderFD17);
	orders.addOrderForDevelopment(orderFD18);
	orders.addOrderForDevelopment(orderFD19);
	orders.addOrderForDevelopment(orderFD20);
	orders.addOrderForDevelopment(orderFD21);
	orders.addOrderForDevelopment(orderFD22);
	orders.addCombinedOrder(cOrder1);
	orders.addCombinedOrder(cOrder2);
	orders.addCombinedOrder(cOrder3);
	orders.addCombinedOrder(cOrder4);
	orders.addCombinedOrder(cOrder5);
	orders.addCombinedOrder(cOrder6);
	orders.addCombinedOrder(cOrder7);
	orders.addCombinedOrder(cOrder8);
	orders.addCombinedOrder(cOrder9);
	orders.addCombinedOrder(cOrder10);
	orders.addCombinedOrder(cOrder11);
	orders.addCombinedOrder(cOrder12);
	orders.addCombinedOrder(cOrder13);
	orders.addCombinedOrder(cOrder14);
	orders.addCombinedOrder(cOrder15);
	orders.addCombinedOrder(cOrder16);
	orders.addCombinedOrder(cOrder17);
	orders.addCombinedOrder(cOrder18);
	orders.addCombinedOrder(cOrder19);
	orders.addCombinedOrder(cOrder20);
	orders.addCombinedOrder(cOrder21);
	orders.addCombinedOrder(cOrder22);

	photoCenter.addSupplier(supplier1);
	photoCenter.addSupplier(supplier2);
	photoCenter.addSupplier(supplier3);
	photoCenter.addSupplier(supplier4);
	photoCenter.addSupplier(supplier5);
	photoCenter.addSupplier(supplier6);
	photoCenter.addSupplier(supplier7);

	photoCenter.addProduct(product1);
	photoCenter.addProduct(product2);
	photoCenter.addProduct(product3);
	photoCenter.addProduct(product4);
	photoCenter.addProduct(product5);
	photoCenter.addProduct(product6);
	photoCenter.addProduct(product7);
	photoCenter.addProduct(product8);
	photoCenter.addProduct(product9);
	photoCenter.addProduct(product10);
	photoCenter.addProduct(product11);

	photoCenter.addClient(client1);
	photoCenter.addClient(client2);
	photoCenter.addClient(client3);
	photoCenter.addClient(client4);
	photoCenter.addClient(client5);
	photoCenter.addClient(client6);
	photoCenter.addClient(client7);
	photoCenter.addClient(client8);
	photoCenter.addClient(client9);
	photoCenter.addClient(client10);
	photoCenter.addClient(client11);
	photoCenter.addClient(client12);
	photoCenter.addClient(client13);
	photoCenter.addClient(client14);
	photoCenter.addClient(client15);
	photoCenter.addClient(client16);

	photoCenter.addWorker(worker0);
	photoCenter.addWorker(worker1);
	photoCenter.addWorker(worker2);
	photoCenter.addWorker(worker3);
	photoCenter.addWorker(worker4);
	photoCenter.addWorker(worker5);
	photoCenter.addWorker(worker6);
	photoCenter.addWorker(worker7);
	photoCenter.addWorker(worker8);
	photoCenter.addWorker(worker9);
	photoCenter.addWorker(worker10);
	photoCenter.addWorker(worker11);
	photoCenter.addWorker(worker12);
	photoCenter.addWorker(worker13);
	photoCenter.addWorker(worker14);
	photoCenter.addWorker(worker15);
	photoCenter.addWorker(worker16);
	photoCenter.addWorker(worker17);
	photoCenter.addWorker(worker18);
	photoCenter.addWorker(worker19);
	photoCenter.addWorker(worker20);
	photoCenter.addWorker(worker21);
	photoCenter.addWorker(worker22);
	photoCenter.addWorker(worker23);
	photoCenter.addWorker(worker24);
	photoCenter.addWorker(worker25);
	photoCenter.addWorker(worker26);
	photoCenter.addWorker(worker27);
	photoCenter.addWorker(worker28);
	photoCenter.addWorker(worker29);
	photoCenter.addWorker(worker30);
	photoCenter.addWorker(worker31);
	photoCenter.addWorker(worker32);
	photoCenter.addWorker(worker33);
	photoCenter.addWorker(worker34);
	photoCenter.addWorker(worker35);
	photoCenter.addWorker(worker36);
	photoCenter.addWorker(worker37);
	photoCenter.addWorker(worker38);
	photoCenter.addWorker(worker39);
	photoCenter.addWorker(worker40);

	cout << "------------------------------------------------------------------------\n";
	cout << "Дані збережено!" << endl;
}