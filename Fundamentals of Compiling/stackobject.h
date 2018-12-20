#pragma once
#include "head.h"

class stackobject
{
private:

	enum datatype resulttype(datatype ob1, datatype ob2)
	{
		if (ob1 == Double || ob2 == Double)
		{
			return Double;
		}
		else if (ob1 == Char || ob2 == Char)
		{
			return Char;
		}
		else
		{
			return Int;
		}
	}

public:

	enum datatype datatype;
	int intdata;
	double doubledata;

	stackobject()
	{
		datatype = Nul;
	}

	stackobject operator - ()
	{
		intdata = -intdata;
		doubledata = -doubledata;
		return *this;
	}

	void assign(stackobject s)
	{
		if (datatype != Double)
		{
			if (s.datatype != Double)
			{
				intdata = s.intdata;
			}
			else
			{
				intdata = (int)s.doubledata;
			}
		}
		else
		{
			if (s.datatype != Double)
			{
				doubledata = s.intdata;
			}
			else
			{
				doubledata = s.doubledata;
			}
		}
	}

	stackobject operator + (const stackobject& s)
	{
		stackobject result;
		if (datatype != Double && s.datatype != Double)
		{
			result.intdata = intdata + s.intdata;
		}
		else if (datatype == Double && s.datatype == Double)
		{
			result.doubledata = doubledata + s.doubledata;
		}
		else if (datatype == Double && s.datatype != Double)
		{
			result.doubledata = doubledata + s.intdata;
		}
		else if (datatype != Double && s.datatype == Double)
		{
			result.doubledata = intdata + s.doubledata;
		}

		result.datatype = resulttype(datatype, s.datatype);
		return result;
	}

	stackobject operator - (const stackobject& s)
	{
		stackobject result;
		if (datatype != Double && s.datatype != Double)
		{
			result.intdata = intdata - s.intdata;
		}
		else if (datatype == Double && s.datatype == Double)
		{
			result.doubledata = doubledata - s.doubledata;
		}
		else if (datatype == Double && s.datatype != Double)
		{
			result.doubledata = doubledata - s.intdata;
		}
		else if (datatype != Double && s.datatype == Double)
		{
			result.doubledata = intdata - s.doubledata;
		}
		result.datatype = resulttype(datatype, s.datatype);
		return result;
	}


	stackobject operator * (const stackobject& s)
	{
		stackobject result;
		if (datatype != Double && s.datatype != Double)
		{
			result.intdata = intdata * s.intdata;
		}
		else if (datatype == Double && s.datatype == Double)
		{
			result.doubledata = doubledata * s.doubledata;
		}
		else if (datatype == Double && s.datatype != Double)
		{
			result.doubledata = doubledata * s.intdata;
		}
		else if (datatype != Double && s.datatype == Double)
		{
			result.doubledata = intdata * s.doubledata;
		}
		result.datatype = resulttype(datatype, s.datatype);
		return result;
	}

	stackobject operator / (const stackobject& s)
	{
		stackobject result;
		if (datatype != Double && s.datatype != Double)
		{
			result.intdata = intdata / s.intdata;
		}
		else if (datatype == Double && s.datatype == Double)
		{
			result.doubledata = doubledata / s.doubledata;
		}
		else if (datatype == Double && s.datatype != Double)
		{
			result.doubledata = doubledata / s.intdata;
		}
		else if (datatype != Double && s.datatype == Double)
		{
			result.doubledata = intdata / s.doubledata;
		}
		result.datatype = resulttype(datatype, s.datatype);
		return result;
	}

	stackobject operator % (const stackobject& s)
	{
		/* The operand of mod operation must be integer */
		if (datatype == Double || s.datatype == Double)
		{
			error(39);
		}
		stackobject result;
		result.intdata = intdata % s.intdata;
		result.datatype = Int;
		return result;
	}

	stackobject operator == (const stackobject& s)
	{
		stackobject result;
		result.datatype = Bool;
		if (datatype != Double && s.datatype != Double)
		{
			result.intdata = (intdata == s.intdata);
		}
		else if (datatype == Double && s.datatype == Double)
		{
			result.intdata = (doubledata == s.doubledata);
		}
		else if (datatype == Double && s.datatype != Double)
		{
			result.intdata = (doubledata == s.intdata);
		}
		else if (datatype != Double && s.datatype == Double)
		{
			result.intdata = (intdata == s.doubledata);
		}
		return result;
	}

	stackobject operator != (const stackobject& s)
	{
		stackobject result;
		result.datatype = Bool;
		if (datatype != Double && s.datatype != Double)
		{
			result.intdata = (intdata != s.intdata);
		}
		else if (datatype == Double && s.datatype == Double)
		{
			result.intdata = (doubledata != s.doubledata);
		}
		else if (datatype == Double && s.datatype != Double)
		{
			result.intdata = (doubledata != s.intdata);
		}
		else if (datatype != Double && s.datatype == Double)
		{
			result.intdata = (intdata != s.doubledata);
		}
		return result;
	}

	stackobject operator > (const stackobject& s)
	{
		stackobject result;
		result.datatype = Bool;
		if (datatype != Double && s.datatype != Double)
		{
			result.intdata = (intdata > s.intdata);
		}
		else if (datatype == Double && s.datatype == Double)
		{
			result.intdata = (doubledata > s.doubledata);
		}
		else if (datatype == Double && s.datatype != Double)
		{
			result.intdata = (doubledata > s.intdata);
		}
		else if (datatype != Double && s.datatype == Double)
		{
			result.intdata = (intdata > s.doubledata);
		}
		return result;
	}

	stackobject operator >= (const stackobject& s)
	{
		stackobject result;
		result.datatype = Bool;
		if (datatype != Double && s.datatype != Double)
		{
			result.intdata = (intdata >= s.intdata);
		}
		else if (datatype == Double && s.datatype == Double)
		{
			result.intdata = (doubledata >= s.doubledata);
		}
		else if (datatype == Double && s.datatype != Double)
		{
			result.intdata = (doubledata >= s.intdata);
		}
		else if (datatype != Double && s.datatype == Double)
		{
			result.intdata = (intdata >= s.doubledata);
		}
		return result;
	}

	stackobject operator < (const stackobject& s)
	{
		stackobject result;
		result.datatype = Bool;
		if (datatype != Double && s.datatype != Double)
		{
			result.intdata = (intdata < s.intdata);
		}
		else if (datatype == Double && s.datatype == Double)
		{
			result.intdata = (doubledata < s.doubledata);
		}
		else if (datatype == Double && s.datatype != Double)
		{
			result.intdata = (doubledata < s.intdata);
		}
		else if (datatype != Double && s.datatype == Double)
		{
			result.intdata = (intdata < s.doubledata);
		}
		return result;
	}

	stackobject operator <= (const stackobject& s)
	{
		stackobject result;
		result.datatype = Bool;
		if (datatype != Double && s.datatype != Double)
		{
			result.intdata = (intdata <= s.intdata);
		}
		else if (datatype == Double && s.datatype == Double)
		{
			result.intdata = (doubledata <= s.doubledata);
		}
		else if (datatype == Double && s.datatype != Double)
		{
			result.intdata = (doubledata <= s.intdata);
		}
		else if (datatype != Double && s.datatype == Double)
		{
			result.intdata = (intdata <= s.doubledata);
		}
		return result;
	}

	stackobject operator && (const stackobject& s)
	{
		if (datatype == Double || s.datatype == Double)
		{
			error(41);
		}
		stackobject result;
		result.intdata = intdata && s.intdata;
		result.datatype = Bool;
		return result;
	}

	stackobject operator || (const stackobject& s)
	{
		if (datatype == Double || s.datatype == Double)
		{
			error(42);
		}
		stackobject result;
		result.intdata = intdata || s.intdata;
		result.datatype = Bool;
		return result;
	}

	stackobject operator ^ (const stackobject& s)
	{
		if (datatype == Double || s.datatype == Double)
		{
			error(44);
		}
		stackobject result;
		result.intdata = intdata ^ s.intdata;
		result.datatype = Bool;
		return result; 
	}

	stackobject operator ! ()
	{
		if (datatype == Double)
		{
			error(43);
		}
		stackobject result;
		result.intdata = !intdata;
		result.datatype = Bool;
		return result;
	}
};

