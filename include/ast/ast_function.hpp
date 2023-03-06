#ifndef ast_function_hpp
#define ast_function_hpp

#include "ast_expression.hpp"

class Function : public Expression {

    private:

        std::string identifier;
        ExpressionPtr arg;
    
    public:

        Function(ExpressionPtr _arg)
            : arg(_arg)
        {}

        virtual ~Function()
        {
            delete arg;
        }

        ExpressionPtr getArg() const
        { return arg; }

        virtual void print(std::ostream &dst) const override
        {
            // dst<<getFunction()<<"( ";
            // arg->print(dst);
            // dst<<" )";
        }

};

#endif
