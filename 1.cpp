#include<iostream>
using namespace std;
#include <vector>
#include <SFML/Graphics.hpp>

struct node
{
	int data;
	node *next;
	node *prev;
};

class DoubleLinkedList
{
private:
	node * head, *tail;
	int idx;
public:
	DoubleLinkedList()
	{
		head = NULL;
		tail = NULL;
		idx = 0;
	}
	void createNode(int value)
	{
		node *temp = new node;
		temp->data = value;
		if (head == tail && head == NULL)
		{
			head = temp;
			tail = temp;
			head->next = tail->next = NULL;
			head->prev = tail->prev = NULL;
		}
		else
		{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
			head->prev = tail;
			tail->next = head;
		}
		idx++;
	}
	void display()
	{
		node *temp = new node;
		temp = head;

		for (int i = 0;i<idx;i++)
		{
			cout << temp->data << "\t";
			temp = temp->next;
		}
		cout << endl;
	}
	void reversedisplay()
	{
		cout << "Reverse List: ";
		node *p1, *p2;
		p1 = head;
		p2 = p1->next;
		p1->next = NULL;
		p1->prev = p2;
		while (p2 != head)
		{
			p2->prev = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = p2->prev;
		}
		tail = head;
		head = p1;
		display();
	}
	void sort(int pick)
	{
		bool swap;
		node *ptr, *lptr = NULL;
		do
		{
			ptr = head;
			swap = false;
			while (lptr != ptr->next)
			{
				char temp;
				if (ptr->data > ptr->next->data && pick == 1)
				{
					swap = true;
					temp = ptr->data;
					ptr->data = ptr->next->data;
					ptr->next->data = temp;
				}
				else if (ptr->data < ptr->next->data && pick == 2)
				{
					swap = true;
					temp = ptr->data;
					ptr->data = ptr->next->data;
					ptr->next->data = temp;
				}
				ptr = ptr->next;
			}
			lptr = ptr;
		} while (swap);
	}
	int getCoor(int find)
	{
		node *temp = new node;
		temp = head;
		for (int i = 0;i < idx; i++)
		{
			int isi=temp->data;
			if (find == i) 
			{
				return isi;
			}
			temp = temp->next;
		}
	}
	int getIdxX(int find) {
		node *temp = new node;
		temp = head;
		for (int i = 0; i < idx; i++)
		{
			if (find == temp->data)
			{
				return i;
			}
			temp = temp->next;
		}
	}
	int getIdxY(int find) {
		node *temp = new node;
		temp = head;
		for (int i = 0; i < idx; i++)
		{
			if (find == temp->data)
			{
				return i;
			}
			temp = temp->next;
		}
	}
};

class Soldier
{
protected:
	double x, y;
	double nextx, nexty;
	bool alive;
	int alternative;
public:
	Soldier()
	{}
	Soldier(double xx, double yy, double nextxx, double nextyy, bool alivee)
	{
		x = xx;
		y = yy;
		nextx = nextxx;
		nexty = nextyy;
		alive = alivee;
	}
	void setX(double xx)
	{
		x = xx;
	}
	double getX()
	{
		return x;
	}
	void setY(double yy)
	{
		y = yy;
	}
	double getY()
	{
		return y;
	}
	void setNextX(double nextxx)
	{
		nextx = nextxx;
	}
	double getNextX()
	{
		return nextx;
	}
	void setNextY(double nextyy)
	{
		nexty = nextyy;
	}
	double getNextY()
	{
		return nexty;
	}
	bool isAlive()
	{
		if (isAlive())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class King : public Soldier
{
protected:

public:
	King()
	{}
	King(double xx, double yy, double nextxx, double nextyy, bool alivee, int alter)
	{
		x = xx;
		y = yy;
		nextx = nextxx;
		nexty = nextyy;
		alive = alivee;
		alternative = alter;
	}
	void setAlter(int alter)
	{
		alternative = alter;
	}
	void getAlter()
	{
		if (alternative == 1)
		{

		}
		else if (alternative == 2)
		{
		}
		else if (alternative == 3)
		{
		}
		else if (alternative == 4)
		{

		}
		else if (alternative == 5)
		{
		}
		else if (alternative == 6)
		{

		}
		else if (alternative == 7)
		{

		}
		else if (alternative == 8)
		{

		}
	}


};

class Rook : public Soldier
{
protected:

public:
	Rook()
	{}
	Rook(double xx, double yy, double nextxx, double nextyy, bool alivee)
	{
		x = xx;
		y = yy;
		nextx = nextxx;
		nexty = nextyy;
		alive = alivee;
	}
	void setAlter(int alter)
	{
		alternative = alter;
	}
	void getAlter()
	{
		if (alternative == 1)
		{

		}
		else if (alternative == 2)
		{
		}
		else if (alternative == 3)
		{
		}
		else if (alternative == 4)
		{

		}
	}
};

class Bishop : public Soldier
{
public:
	Bishop()
	{}
	Bishop(double xx, double yy, double nextxx, double nextyy, bool alivee)
	{
		x = xx;
		y = yy;
		nextx = nextxx;
		nexty = nextyy;
		alive = alivee;
	}
	void setAlter(int alter)
	{
		alternative = alter;
	}
	void getAlter()
	{
		if (alternative == 1)
		{

		}
		else if (alternative == 2)
		{
		}
		else if (alternative == 3)
		{
		}
		else if (alternative == 4)
		{

		}
	}
};

class Pawn : public Soldier
{
protected:
	bool promotion;
public:
	Pawn()
	{}
	Pawn(double xx, double yy, double nextxx, double nextyy, bool alivee, bool promotionn)
	{
		x = xx;
		y = yy;
		nextx = nextxx;
		nexty = nextyy;
		alive = alivee;
		promotion = promotionn;
	}
	void setAlter(int alter)
	{
		alternative = alter;
	}
	void getAlter()
	{
		if (alternative == 1)
		{

		}
		else if (alternative == 2)
		{
		}
		else if (alternative == 3)
		{
		}
		else if (alternative == 4)
		{

		}
		else if (alternative == 5)
		{
		}
		else if (alternative == 6)
		{

		}
		else if (alternative == 7)
		{

		}
		else if (alternative == 8)
		{

		}
	}
	bool isPromotion()
	{
		if (isPromotion())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	//map coordinate list
	DoubleLinkedList mapcoorX, mapcoorY;
	//respawnmerah
	mapcoorX.createNode(28); mapcoorY.createNode(672); //idx 0
	mapcoorX.createNode(193); mapcoorY.createNode(672); //idx 1
	mapcoorX.createNode(361); mapcoorY.createNode(672); //idx 2

	//4
	mapcoorX.createNode(28); mapcoorY.createNode(541); //idx 3
	mapcoorX.createNode(193); mapcoorY.createNode(541); //idx 4
	mapcoorX.createNode(361); mapcoorY.createNode(541); //idx 5

	//3
	mapcoorX.createNode(28); mapcoorY.createNode(410); //idx 6
	mapcoorX.createNode(193); mapcoorY.createNode(410); //idx 7
	mapcoorX.createNode(361); mapcoorY.createNode(410); //idx 8

	//2
	mapcoorX.createNode(28); mapcoorY.createNode(279); //idx 9
	mapcoorX.createNode(193); mapcoorY.createNode(279); //idx 10
	mapcoorX.createNode(361); mapcoorY.createNode(279); //idx 11

	//1
	mapcoorX.createNode(28); mapcoorY.createNode(148); //idx 12
	mapcoorX.createNode(193); mapcoorY.createNode(148); //idx 13
	mapcoorX.createNode(361); mapcoorY.createNode(148); //idx 14

	//respawnbiru
	mapcoorX.createNode(28); mapcoorY.createNode(17); //idx 15
	mapcoorX.createNode(193); mapcoorY.createNode(17); //idx 16
	mapcoorX.createNode(361); mapcoorY.createNode(17); //idx 17


	//object chess piece;
	King kingred, kingblue;
	Rook rookred, rookblue;
	Bishop bishopred, bishopblue;
	Pawn pawnred, pawnblue;

	sf::RenderWindow window(sf::VideoMode(1000,800), "SFML works!");
	sf::Texture back;
	if (!back.loadFromFile("asset/map.jpg"))
	{

	}
	sf::Sprite background(back);
	sf::Vector2f targetSize(500.0f, 800.0f);
	background.setScale(
	targetSize.x / background.getLocalBounds().width,
	targetSize.y / background.getLocalBounds().height);


	//menteribiru
	sf::Texture mb;
	if (!mb.loadFromFile("asset/mentri-biru.jpg"))
	{

	}
	sf::Sprite menteribiru(mb);
	sf::Vector2f mb1(110.f, 110.f);
	menteribiru.setScale(
		mb1.x / menteribiru.getLocalBounds().height,
		mb1.y / menteribiru.getLocalBounds().height);
	


	//rajabiru
	sf::Texture rb;
	if (!rb.loadFromFile("asset/raja-biru.jpg"))
	{

	}
	sf::Sprite rajabiru(rb);
	sf::Vector2f rb1(110.f, 110.f);
	rajabiru.setScale(
		rb1.x / rajabiru.getLocalBounds().height,
		rb1.y / rajabiru.getLocalBounds().height);



	//bentengbiru
	sf::Texture bb;
	if (!bb.loadFromFile("asset/benteng-biru.jpg"))
	{

	}
	sf::Sprite bentengbiru(bb);
	sf::Vector2f bb1(110.f, 110.f);
	bentengbiru.setScale(
		bb1.x / bentengbiru.getLocalBounds().height,
		bb1.y / bentengbiru.getLocalBounds().height);



	//pionbiru
	sf::Texture pb;
	if (!pb.loadFromFile("asset/pion-biru.jpg"))
	{

	}
	sf::Sprite pionbiru(pb);
	sf::Vector2f pb1(110.f, 110.f);
	pionbiru.setScale(
		pb1.x / pionbiru.getLocalBounds().height,
		pb1.y / pionbiru.getLocalBounds().height);


	//starting point biru
	menteribiru.setPosition(sf::Vector2f(28, 148));
	rajabiru.setPosition(sf::Vector2f(193, 148));
	bentengbiru.setPosition(sf::Vector2f(361, 148));
	pionbiru.setPosition(sf::Vector2f(193, 279));
	



	//menterimerah
	sf::Texture mm;
	if (!mm.loadFromFile("asset/mentri-merah.jpg"))
	{

	}
	sf::Sprite menterimerah(mm);
	sf::Vector2f mm2(110.f, 110.f);
	menterimerah.setScale(
		mm2.x / menterimerah.getLocalBounds().height,
		mm2.y / menterimerah.getLocalBounds().height);



	//rajamerah
	sf::Texture rm;
	if (!rm.loadFromFile("asset/raja-merah.jpg"))
	{

	}
	sf::Sprite rajamerah(rm);
	sf::Vector2f rm2(110.f, 110.f);
	rajamerah.setScale(
		rm2.x / rajamerah.getLocalBounds().height,
		rm2.y / rajamerah.getLocalBounds().height);



	//bentengmerah
	sf::Texture bm;
	if (!bm.loadFromFile("asset/benteng-merah.jpg"))
	{

	}
	sf::Sprite bentengmerah(bm);
	sf::Vector2f bm2(110.f, 110.f);
	bentengmerah.setScale(
		bm2.x / bentengmerah.getLocalBounds().height,
		bm2.y / bentengmerah.getLocalBounds().height);



	//pionmerah
	sf::Texture pm;
	if (!pm.loadFromFile("asset/pion-merah.jpg"))
	{

	}
	sf::Sprite pionmerah(pm);
	sf::Vector2f pm2(110.f, 110.f);
	pionmerah.setScale(
		pm2.x / pionmerah.getLocalBounds().height,
		pm2.y / pionmerah.getLocalBounds().height);

	//starting point merah
	bentengmerah.setPosition(sf::Vector2f(28, 541));
	rajamerah.setPosition(sf::Vector2f(193, 541));
	menterimerah.setPosition(sf::Vector2f(361, 541));
	pionmerah.setPosition(sf::Vector2f(193, 410));


	int stat1 = 0;
	int stat2 = 0;
	int turn = 1;
	bool alreadyExecute = false;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			stat1 = 1;
			stat2 = 1;
			alreadyExecute = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			stat1 = 2;
			stat2 = 2;
			alreadyExecute = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			stat1 = 3;
			stat2 = 3;
			alreadyExecute = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			stat1 = 4;
			stat2 = 4;
			alreadyExecute = false;
		}
		if (event.type == sf::Event::KeyReleased)
		{
			if (!alreadyExecute)
			{
				if (event.key.code == sf::Keyboard::Numpad8 )
				{
					if (stat1 == 1 && turn == 1)
					{
						int x = pionbiru.getPosition().x;
						int y = pionbiru.getPosition().y;
						//pionbiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3)));
						turn = 2;
					}
					else if (stat1 == 2 && turn == 1)
					{
						int x = bentengbiru.getPosition().x;
						int y = bentengbiru.getPosition().y;
						bentengbiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3)));
						turn = 2;
					}
					else if (stat1 == 4 && turn == 1)
					{
						int x = rajabiru.getPosition().x;
						int y = rajabiru.getPosition().y;
						rajabiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3)));
						turn = 2;
					}
					//p2
					else if (stat2 == 1 && turn == 2)
					{
						int x = pionmerah.getPosition().x;
						int y = pionmerah.getPosition().y;
						pionmerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3)));
						turn = 1;
					}
					else if (stat2 == 2 && turn == 2)
					{
						int x = bentengmerah.getPosition().x;
						int y = bentengmerah.getPosition().y;
						bentengmerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3)));
						turn = 1;
					}
					else if (stat2 == 4 && turn == 2)
					{
						int x = rajamerah.getPosition().x;
						int y = rajamerah.getPosition().y;
						rajamerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3)));
						turn = 1;
					}
					alreadyExecute = true;
				}
				if (event.key.code == sf::Keyboard::Numpad2)
				{
					if (stat1 == 1 && turn == 1)
					{
						int x = pionbiru.getPosition().x;
						int y = pionbiru.getPosition().y;
						pionbiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
						turn = 2;
					}
					else if (stat1 == 2 && turn == 1)
					{
						int x = bentengbiru.getPosition().x;
						int y = bentengbiru.getPosition().y;
						bentengbiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
						turn = 2;
					}
					else if (stat1 == 4 && turn == 1)
					{
						int x = rajabiru.getPosition().x;
						int y = rajabiru.getPosition().y;
						rajabiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
						turn = 2;
					}
					//p2
					else if (stat2 == 1 && turn == 2)
					{
						int x = pionmerah.getPosition().x;
						int y = pionmerah.getPosition().y;
						pionmerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
						turn = 1;
					}
					else if (stat2 == 2 && turn == 2)
					{
						int x = bentengmerah.getPosition().x;
						int y = bentengmerah.getPosition().y;
						bentengmerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
						turn = 1;
					}
					else if (stat2 == 4 && turn == 2)
					{
						int x = rajamerah.getPosition().x;
						int y = rajamerah.getPosition().y;
						rajamerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x)), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
						turn = 1;
					}
					alreadyExecute = true;
				}
				if (event.key.code == sf::Keyboard::Numpad4)
				{
					if (stat1 == 1 && turn == 1)
					{
						int x = pionbiru.getPosition().x;
						int y = pionbiru.getPosition().y;
						pionbiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y))));
						turn = 2;
					}
					else if (stat1 == 2 && turn == 1)
					{
						int x = bentengbiru.getPosition().x;
						int y = bentengbiru.getPosition().y;
						bentengbiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y))));
						turn = 2;
					}
					else if (stat1 == 4 && turn == 1)
					{
						int x = rajabiru.getPosition().x;
						int y = rajabiru.getPosition().y;
						rajabiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y))));
						turn = 2;
					}
					//p2
					else if (stat2 == 1 && turn == 2)
					{
						int x = pionmerah.getPosition().x;
						int y = pionmerah.getPosition().y;
						pionmerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y))));
						turn = 1;
					}
					else if (stat2 == 2 && turn == 2)
					{
						int x = bentengmerah.getPosition().x;
						int y = bentengmerah.getPosition().y;
						bentengmerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y))));
						turn = 1;
					}
					else if (stat2 == 4 && turn == 2)
					{
						int x = rajamerah.getPosition().x;
						int y = rajamerah.getPosition().y;
						rajamerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y))));
						turn = 1;
					}
					alreadyExecute = true;
				}
				if (event.key.code == sf::Keyboard::Numpad6)
				{
					if (stat1 == 1 && turn == 1)
					{
						int x = pionbiru.getPosition().x;
						int y = pionbiru.getPosition().y;
						pionbiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y))));
						turn = 2;
					}
					else if (stat1 == 2 && turn == 1)
					{
						int x = bentengbiru.getPosition().x;
						int y = bentengbiru.getPosition().y;
						bentengbiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y))));
						turn = 2;
					}
					else if (stat1 == 4 && turn == 1)
					{
						int x = rajabiru.getPosition().x;
						int y = rajabiru.getPosition().y;
						rajabiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y))));
						turn = 2;
					}
					//p2
					else if (stat2 == 1 && turn == 2)
					{
						int x = pionmerah.getPosition().x;
						int y = pionmerah.getPosition().y;
						pionmerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y))));
						turn = 1;
					}
					else if (stat2 == 2 && turn == 2)
					{
						int x = bentengmerah.getPosition().x;
						int y = bentengmerah.getPosition().y;
						bentengmerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y))));
						turn = 1;
					}
					else if (stat2 == 4 && turn == 2)
					{
						int x = rajamerah.getPosition().x;
						int y = rajamerah.getPosition().y;
						rajamerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y))));
						turn = 1;
					}
					alreadyExecute = true;
				}
				if (event.key.code == sf::Keyboard::Numpad7)
				{
					if (stat1 == 3 && turn == 1)
					{
						int x = menteribiru.getPosition().x;
						int y = menteribiru.getPosition().y;
						menteribiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y)+3)));
						turn = 2;
					}
					else if (stat1 == 4 && turn == 1)
					{
						int x = rajabiru.getPosition().x;
						int y = rajabiru.getPosition().y;
						rajabiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y)+3)));
						turn = 2;
					}
					//p2
					else if (stat2 == 3 && turn == 2)
					{
						int x = menterimerah.getPosition().x;
						int y = menterimerah.getPosition().y;
						menterimerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3)));
						turn = 1;
					}
					else if (stat2 == 4 && turn == 2)
					{
						int x = rajamerah.getPosition().x;
						int y = rajamerah.getPosition().y;
						rajamerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3)));
						turn = 1;
					}
					alreadyExecute = true;
				}
				if (event.key.code == sf::Keyboard::Numpad9)
				{
					if (stat1 == 3 && turn == 1)
					{
						int x = menteribiru.getPosition().x;
						int y = menteribiru.getPosition().y;
						menteribiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3)));
						turn = 2;
					}
					else if (stat1 == 4 && turn == 1)
					{
						int x = rajabiru.getPosition().x;
						int y = rajabiru.getPosition().y;
						rajabiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3)));
						turn = 2;
					}
					//p2
					else if (stat2 == 3 && turn == 2)
					{
						int x = menterimerah.getPosition().x;
						int y = menterimerah.getPosition().y;
						menterimerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3)));
						turn = 1;
					}
					else if (stat2 == 4 && turn == 2)
					{
						int x = rajamerah.getPosition().x;
						int y = rajamerah.getPosition().y;
						rajamerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) + 3)));
						turn = 1;
					}
					alreadyExecute = true;
				}
				if (event.key.code == sf::Keyboard::Numpad1)
				{
					if (stat1 == 3 && turn == 1)
					{
						int x = menteribiru.getPosition().x;
						int y = menteribiru.getPosition().y;
						menteribiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
						turn = 2;
					}
					else if (stat1 == 4 && turn == 1)
					{
						int x = rajabiru.getPosition().x;
						int y = rajabiru.getPosition().y;
						rajabiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
						turn = 2;
					}
					//p2
					else if (stat2 == 3 && turn == 2)
					{
						int x = menterimerah.getPosition().x;
						int y = menterimerah.getPosition().y;
						menterimerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
						turn = 1;
					}
					else if (stat2 == 4 && turn == 2)
					{
						int x = rajamerah.getPosition().x;
						int y = rajamerah.getPosition().y;
						rajamerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) - 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
						turn = 1;
					}
					alreadyExecute = true;
				}
				if (event.key.code == sf::Keyboard::Numpad3)
				{
					if (stat1 == 3 && turn == 1)
					{
						int x = menteribiru.getPosition().x;
						int y = menteribiru.getPosition().y;
						menteribiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
						turn = 2;
					}
					else if (stat1 == 4 && turn == 1)
					{
						int x = rajabiru.getPosition().x;
						int y = rajabiru.getPosition().y;
						rajabiru.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
						turn = 2;
					}
					//p2
					else if (stat2 == 3 && turn == 2)
					{
						int x = menterimerah.getPosition().x;
						int y = menterimerah.getPosition().y;
						menterimerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
						turn = 1;
					}
					else if (stat2 == 4 && turn == 2)
					{
						int x = rajamerah.getPosition().x;
						int y = rajamerah.getPosition().y;
						rajamerah.setPosition(sf::Vector2f(mapcoorX.getCoor(mapcoorX.getIdxX(x) + 1), mapcoorY.getCoor(mapcoorY.getIdxY(y) - 3)));
						turn = 1;
					}
					alreadyExecute = true;
				}
			}
		}
		window.clear();
	
		window.draw(background);
		window.draw(pionbiru);
		window.draw(menteribiru);
		window.draw(rajabiru);
		window.draw(bentengbiru);
		
		window.draw(pionmerah);
		window.draw(menterimerah);
		window.draw(rajamerah);
		window.draw(bentengmerah);
		window.display();
	}
	
	return 0;
}

