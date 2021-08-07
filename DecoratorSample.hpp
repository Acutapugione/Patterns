// Дан класс, реализация не известн
class	Watt {
public:
	void		LogUnit(unsigned int unit);
	void		LogMeasure(const char* m = "W");
	void		Error(const String& s);
};

void	Watt::LogUnit(unsigned int unit)
{
	Cout() << unit;
}

void	Watt::LogMeasure(const char* m)
{
	Cout() << m;
}

void	Watt::Error(const String& s)
{
	Cout() << " Error: " << s << EOL;
}

class	Decor {
public:
	virtual				~Decor() 			{}
	virtual	void		LogUnit(uint64 unit)
	{
		if(INT32_MAX<=unit)
		{
			w.LogUnit(0);
			Error("overflow");
		}
		else
			w.LogUnit(static_cast<unsigned int>(unit));
	}
	virtual	void		LogMeasure(const char* m = "W")	{ w.LogMeasure(m); }
	virtual	void		Error(const String& s)		{ w.Error(s); }

private:
	Watt	w;
};

class DecorW : public Decor {
public:
	DecorW(Decor* d = NULL) : w(d)		{}
	~DecorW() { if (w) delete w; }
	void		LogUnit(uint64 unit)	{
		Decor::LogUnit(unit % 1000);
		LogMeasure();
		if (NULL != w)
			w->LogUnit(unit);
	}
	void		LogMeasure(const char* m = " WT ")	{ Decor::LogMeasure(m); }
private:
	Decor*	w;
};

class DecorK : public Decor {
public:
	DecorK(Decor* d = NULL) : w(d)		{}
	~DecorK() { if (w) delete w; }
	void		LogUnit(uint64 unit)	{
		Decor::LogUnit((unit / 1000) % 1000);
		LogMeasure();
		if (NULL != w)
			w->LogUnit(unit);
	}
	void		LogMeasure(const char* m = " KWT ")	{ Decor::LogMeasure(m); }

private:
	Decor*	w;
};

class DecorM : public Decor {
public:
	DecorM(Decor* d = NULL) : w(d)		{}
	~DecorM() { if (w) delete w; }
	void		LogUnit(uint64 unit)	{
		Decor::LogUnit((unit / 1000000) % 1000);
		LogMeasure();
		if (NULL != w)
			w->LogUnit(unit);
	}
	void		LogMeasure(const char* m = " MWT ")	{ Decor::LogMeasure(m); }

private:
	Decor*	w;
};

class DecorG : public Decor {
public:
	DecorG(Decor* d = NULL) : w(d)		{}
	~DecorG() { if (w) delete w; }
	void		LogUnit(uint64 unit)	{
		Decor::LogUnit((unit / 1000000000) % 1000);
		LogMeasure();
		if (NULL != w)
			w->LogUnit(unit);
	}
	void		LogMeasure(const char* m = " GWT ")	{ Decor::LogMeasure(m); }

private:
	Decor*	w;
};

void doMain()
{
	static const uint64 MaxWatt = 1000000000000;

	// Как выдает показания по старому
	for (int i = 0; i < 10; i++) {
		int64	real = Random64(MaxWatt) + INT32_MAX; // Иммитация что нам не хватает разрядности
		Watt	w;

		Cout() << "Real: " << real << '\t' << "Show: ";

		w.LogUnit(real);
		Cout() << ' ';
		w.LogMeasure();

		Cout() << EOL;
	}

	for (int i = 0; i < 10; i++) {
		int64	real = Random64(MaxWatt) + INT32_MAX; // Иммитация что нам не хватает разрядности
//		DecorW  w(new DecorK(new DecorM(new DecorG)));
		DecorG  w(new DecorM(new DecorK(new DecorW)));



		Cout() << "Real: " << real << '\t' << "Show: ";

		w.LogUnit(real);
		Cout() << EOL;

	}



}


