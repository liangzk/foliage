#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {Con, Var, Sum, Diff, Prod, Quot} ExprType; 

typedef struct _expression_ {
    ExprType type; 
    union _data_ {
	float con; 
	char var[128]; 
	struct _compose_ { 
	    struct _expression_ *first; 
	    struct _expression_ *second;
	} comp;
    } data;

} Expression; 

Expression *con(float value) 
{
    Expression *result; 
    result = (Expression*)malloc(sizeof(Expression)); 
    result->type = Con; 
    result->data.con = value;
    return result; 
}

Expression *var(const char *value) 
{
    Expression *result; 
    result = (Expression*)malloc(sizeof(Expression)); 
    result->type = Var; 
    strncpy(result->data.var, value, sizeof(result->data.var));
    return result; 
}

void setsubexpr(Expression *result, Expression *first, Expression *second) 
{
    result->data.comp.first = first;
    result->data.comp.second = second; 
}

Expression *sum(Expression *first, Expression *second)
{
    Expression *result; 
    result = (Expression*)malloc(sizeof(Expression)); 
    result->type = Sum; 
    setsubexpr(result, first, second); 
    return result;
}

Expression *diff(Expression *first, Expression *second)
{
    Expression *result; 
    result = (Expression*)malloc(sizeof(Expression)); 
    result->type = Diff; 
    setsubexpr(result, first, second); 
    return result;
}

Expression *prod(Expression *first, Expression *second)
{
    Expression *result; 
    result = (Expression*)malloc(sizeof(Expression)); 
    result->type = Prod; 
    setsubexpr(result, first, second); 
    return result;
}

Expression *quot(Expression *first, Expression *second)
{
    Expression *result; 
    result = (Expression*)malloc(sizeof(Expression)); 
    result->type = Quot; 
    setsubexpr(result, first, second); 
    return result;
}

Expression *fst(Expression *expr)
{
    return expr->data.comp.first; 
}

Expression *snd(Expression *expr)
{
    return expr->data.comp.second; 
}

Expression *deriv(Expression *expr, const char *var) 
{
    Expression *result; 
    switch (expr->type) {
    case Con:
	result = con(0); 
	break; 
    case Var:
	if (strcmp(var, expr->data.var) == 0) {
	    result = con(1); 
	} else {
	    result = con(0); 
	}
	break; 
    case Sum: 
	result = sum(deriv(fst(expr), var), deriv(snd(expr), var));
	break; 
    case Diff:
	result = diff(deriv(fst(expr), var), deriv(snd(expr), var));
	break; 
    case Prod:
	result = sum(prod(fst(expr), deriv(snd(expr), var)), 
		     prod(deriv(fst(expr), var), snd(expr))); 
	break; 
    case Quot:
	result = quot(diff(prod(deriv(fst(expr), var), snd(expr)),
			   prod(fst(expr), deriv(snd(expr), var))),
		      prod(snd(expr), snd(expr))); 
	break; 
    default:
	exit(1);
	break; 
    }
    return result; 
}

void open_paren(int prec, int op_prec) 
{
    if (prec > op_prec) printf("("); 
}

void close_paren(int prec, int op_prec)
{
    if (prec > op_prec) printf(")");
}

void print_op(ExprType type)
{
    switch (type) {
    case Sum:
	printf(" + ");
	break; 
    case Diff:
	printf(" - ");
	break; 
    case Prod:
	printf(" * ");
	break; 
    case Quot:
	printf(" / ");
	break; 
    default:
	break;
    }
}

void print(int prec, Expression *expr) 
{
    switch (expr->type) {
    case Con:
	printf("%.0f", expr->data.con); 
	break; 
    case Var:
	printf("%s", expr->data.var); 
	break; 
    case Sum:
	open_paren(prec, 0);
	print(0, expr->data.comp.first);
	print_op(expr->type);
	print(0, expr->data.comp.second); 
	close_paren(prec, 0);
	break; 
    case Diff:
	open_paren(prec, 0);
	print(0, expr->data.comp.first);
	print_op(expr->type);
	print(1, expr->data.comp.second); 
	close_paren(prec, 0);
	break; 
    case Prod:
	open_paren(prec, 2);
	print(2, expr->data.comp.first);
	print_op(expr->type);
	print(2, expr->data.comp.second); 
	close_paren(prec, 2);
	break; 
    case Quot:
	open_paren(prec, 2);
	print(2, expr->data.comp.first);
	print_op(expr->type);
	print(3, expr->data.comp.second); 
	close_paren(prec, 2);
	break; 
    default:
	break; 
    }
}

void print_expr(Expression *expr) 
{
    if (!expr)
	return; 

    print(0, expr); 
    printf("\n");
}

int main()
{
    Expression *expr, *result;

    /* x/(1+x*x) */
    expr = quot(var("x"), sum(con(1), prod(var("x"), var("x")))); 
    print_expr(expr);
    result = deriv(expr, "x"); 
    print_expr(result); 
    return 0;
}
