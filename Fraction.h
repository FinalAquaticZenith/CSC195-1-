#pragma once

namespace mathLib {
	template <typename T>
	class Fraction
	{
	public:
		Fraction();
		Fraction(T numer, T denom) {
			if (denom != 0) {
			m_numer = numer;
			m_denom = denom;
			}
			else
			{
				m_denom = 1;
			}
		}
		void Set(T numerator, T denominator) {
			m_denom = denominator;
			m_numer = numerator;
		}
		float ToFloat() const { return m_numer / (float)m_denom; }
		Fraction operator + (const Fraction& other) { return Fraction{(m_numer * other.m_denom + other.m_denom * other.m_numer) / (m_denom * other.m_denom) }; }
		Fraction operator - (const Fraction& other) { return Fraction{(m_numer * other.m_denom - m_denom * other.m_numer) / (m_denom * other.m_denom) }; }
		Fraction operator * (const Fraction& other) { return Fraction{(m_numer * other.m_numer) / (m_denom * other.m_denom) }; }
		Fraction operator / (const Fraction& other) { return Fraction{(m_numer * other.m_denom) / (m_denom * other.m_numer) }; }

		bool operator == (const Fraction& other) const { return m_numer == other.m_numer && m_denom == other.m_denom; }
		bool operator != (const Fraction& other) const { return !(*this == other); }
		bool operator <= (const Fraction& other) const { return this->ToFloat() <= other.ToFloat(); }
		bool operator <(const Fraction& other) const { return this->ToFloat() < other.ToFloat(); }
		bool operator >=(const Fraction& other) const { return this->ToFloat() >= other.ToFloat(); }
		bool operator >(const Fraction& other) const { return this->ToFloat() >= other.ToFloat(); }

		void Simplify()
		{
			if (m_denom < 0)
			{
				m_denom *= -1;
				m_numer *= -1;
			}
			T gcd = findGCD(m_numer, m_denom);
			m_denom /= gcd;
			m_numer /= gcd;
			return;
		}
		friend std::ostream& operator << (std::ostream& output, const Fraction& b)
		{
			output << b.m_numer << " " << b.m_denom;

			return output;
		}
		friend std::istream& operator >> (std::istream& input, Fraction& b) {
			// Read the numerator and denominator, separated by '/'
			input >> b.m_numer;
			if (input.peek() == '/') {
				input.ignore();
				input >> b.m_denom;
			}
			else {
				b.m_denom = 1; // Default denominator if '/' is absent
			}
			return input;
		}

		T findGCD(int a, int b) {

			while (b != 0) {
				int temp = b;
				b = a % b;
				a = temp;
			}
			return a;
		}


	private:
		T m_numer;
		T m_denom;
	};

};
