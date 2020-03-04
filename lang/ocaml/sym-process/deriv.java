public class deriv 
{
    static final int Con = 0; 
    static final int Var = 1;
    static final int Sum = 2;
    static final int Diff = 3;
    static final int Prod = 4;
    static final int Quot = 5;

    static class Expression {
	public int type; 
	public float con; 
	public String var; 
	public Expression first; 
	public Expression second;
    };

    static Expression con(float value) {
	Expression result = new Expression(); 
	result.type = Con; 
	result.con = value;
	return result; 
    }

    static Expression var(String value) {
	Expression result = new Expression(); 
	result.type = Var; 
	result.var = value; 
	return result; 
    }

    static Expression sum(Expression first, Expression second) {
	Expression result = new Expression();  
	result.type = Sum;
	result.first = first; 
	result.second = second;
	return result;
    }

    static Expression diff(Expression first, Expression second) {
	Expression result = new Expression(); 
	result.type = Diff; 
	result.first = first;
	result.second = second; 
	return result;
    }

    static Expression prod(Expression first, Expression second) {
	Expression result = new Expression(); 
	result.type = Prod; 
	result.first = first; 
	result.second = second; 
	return result;
    }

    static Expression quot(Expression first, Expression second) {
	Expression result = new Expression(); 
	result.type = Quot; 
	result.first = first; 
	result.second = second; 
	return result;
    }
    
    static Expression fst(Expression expr) {
	return expr.first; 
    }

    static Expression snd(Expression expr) {
	return expr.second; 
    }


    static Expression do_deriv(Expression expr, String var) {
	Expression result;
	result = con(0);
	switch (expr.type) {
	case Con:
	    result = con(0); 
	    break; 
	case Var:
	    if (var == expr.var) {
		result = con(1); 
	    } else {
		result = con(0); 
	    }
	    break; 
	case Sum: 
	    result = sum(do_deriv(fst(expr), var), do_deriv(snd(expr), var));
	    break; 
	case Diff:
	    result = diff(do_deriv(fst(expr), var), do_deriv(snd(expr), var));
	    break; 
	case Prod:
	    result = sum(prod(fst(expr), do_deriv(snd(expr), var)), 
			 prod(do_deriv(fst(expr), var), snd(expr))); 
	    break; 
	case Quot:
	    result = quot(diff(prod(do_deriv(fst(expr), var), snd(expr)),
			       prod(fst(expr), do_deriv(snd(expr), var))),
			  prod(snd(expr), snd(expr))); 
	    break; 
	default:
	    System.exit(1);
	    break; 
	}
	return result; 
    }

    static void open_paren(int prec, int op_prec) {
	if (prec > op_prec) System.out.print("("); 
    }

    static void close_paren(int prec, int op_prec) {
	if (prec > op_prec) System.out.print(")");
    }

    static void print_op(int type) {
	switch (type) {
	case Sum:
	    System.out.print(" + ");
	    break; 
	case Diff:
	    System.out.print(" - ");
	    break; 
	case Prod:
	    System.out.print(" * ");
	    break; 
	case Quot:
	    System.out.print(" / ");
	    break; 
	default:
	    break;
	}
    }
    
    static void print(int prec, Expression expr) {
	switch (expr.type) {
	case Con:
	    System.out.print(expr.con); 
	    break; 
	case Var:
	    System.out.print(expr.var); 
	    break; 
	case Sum:
	    open_paren(prec, 0);
	    print(0, expr.first);
	    print_op(expr.type);
	    print(0, expr.second); 
	    close_paren(prec, 0);
	    break; 
	case Diff:
	    open_paren(prec, 0);
	    print(0, expr.first);
	    print_op(expr.type);
	    print(1, expr.second); 
	    close_paren(prec, 0);
	    break; 
	case Prod:
	    open_paren(prec, 2);
	    print(2, expr.first);
	    print_op(expr.type);
	    print(2, expr.second); 
	    close_paren(prec, 2);
	    break; 
	case Quot:
	    open_paren(prec, 2);
	    print(2, expr.first);
	    print_op(expr.type);
	    print(3, expr.second); 
	    close_paren(prec, 2);
	    break; 
	default:
	    break; 
	}
    }

    static void print_expr(Expression expr) {
	print(0, expr); 
	System.out.print("\n");
    }
    
    public static void main(String args[]) {
	Expression expr, result;

	/* x/(1+x*x) */
	expr = quot(var("x"), sum(con(1), prod(var("x"), var("x")))); 
	print_expr(expr);
	result = do_deriv(expr, "x"); 
	print_expr(result); 
    }
}
