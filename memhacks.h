std::string a_s;
	int foo;

	friend void printInternals(const B&);
	friend void printInternals(B& b);

public:
	std::string getBString() const;
	A();

	virtual std::string getBString() const;
	virtual float getData(int idx) const;
	void printData(std::ostream& os);
	void printData2(std::ostream& os);
};
@@ -21,10 +24,13 @@ class B : public A {
	std::string b_s;
	float data[7];

	friend void printInternals(const B&);
	friend void printInternals(B& b);

public:
	B();

	virtual std::string getBString() const;
	virtual float getData(int idx) const;
};

void printInternals(const B& b);
void printInternals(B& b);
