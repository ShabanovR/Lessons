#pragma once
#include <cstring>
#include <climits>
#include <map>
#include <set>
#include "token.h"
#include "Parser.h"
#include "Function.h"



static class Cmd {
	std::set<int> return_cmd;
	std::map<std::string, int> cmd_table;

	void define_variable();
	void out_string(std::string&);

	int get_params_cnt();
	void get_fun_body(std::string&);

	void skip_executive_block();
	void skip_rest_conditional();
	void following_branch();
	void jump_to_another_word();

	void cmd_print();
	void cmd_input();
	void cmd_if();
	void cmd_else();
	void cmd_elif();
	void cmd_while();
	void cmd_for();
	void cmd_fun();
	void cmd_let();
	void cmd_break();
	void cmd_return();
	
	void cmd_sin();
	void cmd_cos();
	void cmd_log();
	void cmd_exp();

public:
	Cmd();
	~Cmd();

	bool is_return_cmd(int);
	bool is_logic_oper(int);
	bool is_cmd(const std::string& _cmd, int& pos);

	void execute(int cmd_token);

	void clear();
} cmd;



class Executive {
	void invert_opers(); // opers from token.h
	void eval_var();

	double get_value();
	double get_number(std::string&);

	bool not_executive() const;
	bool get_condition_not();
	bool contains_alnum(std::string&) const;
	bool contains_number(char) const;

public:
	void eval();
	void assign_variable();

	double compute_expr();

	void read_param_value(std::vector<double>&);
};
extern Executive exec;



static class FunFunctor {
	void execute(std::vector<double>&);
	void add_fun_vars(std::vector<double>&);
public:
	void operator()(const std::string&);
} execute_fun;