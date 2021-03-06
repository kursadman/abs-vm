#ifndef OPEFACT_H
# define OPEFACT_H
# include "IOperand.hpp"
//#include "Operand.tpp"

//# include "OperandInt8.hpp"
//# include "OperandInt16.hpp"
//# include "OperandInt32.hpp"
# include <map>

//class Operand<int>;
//template <typename T>
//class Operand;

class FactoryOperand
{
	public:
		FactoryOperand();
		FactoryOperand(FactoryOperand const &src);
		~FactoryOperand();
		FactoryOperand&	operator=(FactoryOperand const &rhs);
		IOperand		*make(eOperandType op, std::string val);
		IOperand		*make(eOperandType op, double val);
		IOperand		*make(eOperandType op);
		//IOperand		*make(std::string str);

		static FactoryOperand	Factory;
		static bool				compareInt32(IOperand *a, IOperand *b);
		static bool				compareInt16(IOperand *a, IOperand *b);
		static bool				compareInt8(IOperand *a, IOperand *b);
		static bool				compareFloat(IOperand *a, IOperand *b);
		static bool				compareDouble(IOperand *a, IOperand *b);

	private:
		IOperand			*makeInt32();
		IOperand			*createInt32(std::string val);
		IOperand			*makeInt32(double val);

		IOperand			*makeInt16();
		IOperand			*createInt16(std::string val);
		IOperand			*makeInt16(double val);

		IOperand			*makeInt8();
		IOperand			*createInt8(std::string val);
		IOperand			*makeInt8(double val);

		IOperand			*makeFloat();
		IOperand			*createFloat(std::string val);
		IOperand			*makeFloat(double val);

		IOperand			*makeDouble();
		IOperand			*createDouble(std::string val);
		IOperand			*makeDouble(double val);


};

std::ostream	&operator<<(std::ostream &o, FactoryOperand const &rhs);

typedef IOperand* (FactoryOperand::*t_ope)();
typedef IOperand* (FactoryOperand::*t_opestr)(std::string);
typedef IOperand* (FactoryOperand::*t_opedouble)(double);


//#include "Operand.tpp"

#endif
