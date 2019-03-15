template <class A, class B>
class Monomio{

private:
	A coeficiente;
	B exponente;

public:

	Monomio(A coef, B exp) : coeficiente(coef), exponente(exp){};

	A getCoeficiente() const { return coeficiente; };
	B getExponente() const { return exponente; };
	void setCoeficiente(int valor){ coeficiente = valor; }

	bool operator<(const Monomio & mon) const{
		return (this->exponente < mon.exponente);
	}

};