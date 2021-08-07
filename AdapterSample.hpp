//+++ Классы созданные кем-то, изменять нельзя
class Amper {
public:

	Amper( int value ) : value(value)	{}

	String	Log() const		{ return Format("%d A", value); }

private:
	int		value;
};

class Volt {
public:

	Volt( int value ) : value(value)	{}

	String	Log() const		{ return Format("%d V", value); }

private:
	int		value;
};

class Watt {
public:

	Watt( int value ) : value(value)	{}

	String	Log() const		{ return Format("%d W", value); }

private:
	int		value;
};

class	Ampermetr {
public:
	Ampermetr( int max )	: max(max)	{}

	Amper	operator()() const	{ return Amper(Random(max)); }

private:
	int		max;
};

class	Voltmetr {
public:
	Voltmetr( int max )	: max(max)	{}

	Volt	operator()() const	{ return Volt(Random(max)); }

private:
	int		max;
};

class	WattLogger {
public:
	void	Log(const Watt& w) const		{ Cout() << w.Log() << EOL; }
};
//--- Классы созданные кем-то, изменять нельзя

//+++ Адаптеры и прокси

class Adapter {

public:
	Adapter(const String& s)	{ value = StrInt(s); }
	Adapter(const Volt& volt)	{ value = StrInt(volt.Log());}
	Adapter(const Amper& amper) { value = StrInt(amper.Log());}

	int	operator()() const		{ return value; }

private:
	int value;
};

class ProxyWattLogger : public WattLogger {
public:
	ProxyWattLogger(Ampermetr& a, Voltmetr& v)
		: a(a), v(v)	{}

	void	Log(const Watt& w) const {
		int adapav = Adapter(a())();
		int adapvv = Adapter(v())();

		Cout() << Amper(adapav).Log() << '\t';
		Cout() << Volt(adapvv).Log() << '\t';

		/*int av = Adapter(a().Log())();
		int	vv = Adapter(v().Log())();*/
		/*Cout() << Amper(av).Log() << '\t';
		Cout() << Volt(vv).Log() << '\t';*/


		WattLogger::Log(Watt(adapvv * adapav));
	}

private:
	Ampermetr&	a;
	Voltmetr&	v;
};
//--- Адаптеры и прокси

// Основная прога
static	const	int	MaxVolt  = 220;
static	const	int	MaxAmper = 10;
static	const	int	MaxWatt  = MaxVolt * MaxAmper;

void doMain()
{
	Ampermetr	a(10);
	Voltmetr	v(220);
	WattLogger	logger;

	// Как выдает показания по старому
	for (int i = 0; i < 10; i++) {
			logger.Log(Watt(Random(MaxWatt)));}

	// Необходимо вывести в виде: XXX A; XXX V; XXX W
	for (int i = 0; i < 10; i++) {
		ProxyWattLogger(a, v).Log(Watt(0));
	}



}

