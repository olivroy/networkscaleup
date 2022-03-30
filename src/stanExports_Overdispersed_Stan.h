// Generated by rstantools.  Do not edit by hand.

/*
    networkscaleup is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    networkscaleup is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with networkscaleup.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.21.0
#include <stan/model/model_header.hpp>
namespace model_Overdispersed_Stan_namespace {
using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;
static int current_statement_begin__;
stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_Overdispersed_Stan");
    reader.add_event(45, 43, "end", "model_Overdispersed_Stan");
    return reader;
}
#include <stan_meta_header.hpp>
class model_Overdispersed_Stan
  : public stan::model::model_base_crtp<model_Overdispersed_Stan> {
private:
        int n_i;
        int n_k;
        std::vector<std::vector<int> > y;
public:
    model_Overdispersed_Stan(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, 0, pstream__);
    }
    model_Overdispersed_Stan(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : model_base_crtp(0) {
        ctor_body(context__, random_seed__, pstream__);
    }
    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;
        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning
        current_statement_begin__ = -1;
        static const char* function__ = "model_Overdispersed_Stan_namespace::model_Overdispersed_Stan";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        try {
            // initialize data block variables from context__
            current_statement_begin__ = 3;
            context__.validate_dims("data initialization", "n_i", "int", context__.to_vec());
            n_i = int(0);
            vals_i__ = context__.vals_i("n_i");
            pos__ = 0;
            n_i = vals_i__[pos__++];
            check_greater_or_equal(function__, "n_i", n_i, 0);
            current_statement_begin__ = 4;
            context__.validate_dims("data initialization", "n_k", "int", context__.to_vec());
            n_k = int(0);
            vals_i__ = context__.vals_i("n_k");
            pos__ = 0;
            n_k = vals_i__[pos__++];
            check_greater_or_equal(function__, "n_k", n_k, 0);
            current_statement_begin__ = 5;
            validate_non_negative_index("y", "n_i", n_i);
            validate_non_negative_index("y", "n_k", n_k);
            context__.validate_dims("data initialization", "y", "int", context__.to_vec(n_i,n_k));
            y = std::vector<std::vector<int> >(n_i, std::vector<int>(n_k, int(0)));
            vals_i__ = context__.vals_i("y");
            pos__ = 0;
            size_t y_k_0_max__ = n_i;
            size_t y_k_1_max__ = n_k;
            for (size_t k_1__ = 0; k_1__ < y_k_1_max__; ++k_1__) {
                for (size_t k_0__ = 0; k_0__ < y_k_0_max__; ++k_0__) {
                    y[k_0__][k_1__] = vals_i__[pos__++];
                }
            }
            // initialize transformed data variables
            // execute transformed data statements
            // validate transformed data
            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 10;
            validate_non_negative_index("alphas", "n_i", n_i);
            num_params_r__ += n_i;
            current_statement_begin__ = 11;
            validate_non_negative_index("betas", "n_k", n_k);
            num_params_r__ += n_k;
            current_statement_begin__ = 12;
            validate_non_negative_index("inv_omegas", "n_k", n_k);
            num_params_r__ += n_k;
            current_statement_begin__ = 13;
            num_params_r__ += 1;
            current_statement_begin__ = 14;
            num_params_r__ += 1;
            current_statement_begin__ = 15;
            num_params_r__ += 1;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    ~model_Overdispersed_Stan() { }
    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;
        current_statement_begin__ = 10;
        if (!(context__.contains_r("alphas")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable alphas missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("alphas");
        pos__ = 0U;
        validate_non_negative_index("alphas", "n_i", n_i);
        context__.validate_dims("parameter initialization", "alphas", "vector_d", context__.to_vec(n_i));
        Eigen::Matrix<double, Eigen::Dynamic, 1> alphas(n_i);
        size_t alphas_j_1_max__ = n_i;
        for (size_t j_1__ = 0; j_1__ < alphas_j_1_max__; ++j_1__) {
            alphas(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_unconstrain(alphas);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable alphas: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 11;
        if (!(context__.contains_r("betas")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable betas missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("betas");
        pos__ = 0U;
        validate_non_negative_index("betas", "n_k", n_k);
        context__.validate_dims("parameter initialization", "betas", "vector_d", context__.to_vec(n_k));
        Eigen::Matrix<double, Eigen::Dynamic, 1> betas(n_k);
        size_t betas_j_1_max__ = n_k;
        for (size_t j_1__ = 0; j_1__ < betas_j_1_max__; ++j_1__) {
            betas(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_unconstrain(betas);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable betas: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 12;
        if (!(context__.contains_r("inv_omegas")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable inv_omegas missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("inv_omegas");
        pos__ = 0U;
        validate_non_negative_index("inv_omegas", "n_k", n_k);
        context__.validate_dims("parameter initialization", "inv_omegas", "vector_d", context__.to_vec(n_k));
        Eigen::Matrix<double, Eigen::Dynamic, 1> inv_omegas(n_k);
        size_t inv_omegas_j_1_max__ = n_k;
        for (size_t j_1__ = 0; j_1__ < inv_omegas_j_1_max__; ++j_1__) {
            inv_omegas(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.vector_lub_unconstrain(0, 1, inv_omegas);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable inv_omegas: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 13;
        if (!(context__.contains_r("sigma_alpha")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable sigma_alpha missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("sigma_alpha");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "sigma_alpha", "double", context__.to_vec());
        double sigma_alpha(0);
        sigma_alpha = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0, sigma_alpha);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable sigma_alpha: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 14;
        if (!(context__.contains_r("mu_beta")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable mu_beta missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("mu_beta");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "mu_beta", "double", context__.to_vec());
        double mu_beta(0);
        mu_beta = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(mu_beta);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable mu_beta: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        current_statement_begin__ = 15;
        if (!(context__.contains_r("sigma_beta")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable sigma_beta missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("sigma_beta");
        pos__ = 0U;
        context__.validate_dims("parameter initialization", "sigma_beta", "double", context__.to_vec());
        double sigma_beta(0);
        sigma_beta = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0, sigma_beta);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable sigma_beta: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }
    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }
    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {
        typedef T__ local_scalar_t__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning
        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
            // model parameters
            current_statement_begin__ = 10;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> alphas;
            (void) alphas;  // dummy to suppress unused var warning
            if (jacobian__)
                alphas = in__.vector_constrain(n_i, lp__);
            else
                alphas = in__.vector_constrain(n_i);
            current_statement_begin__ = 11;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> betas;
            (void) betas;  // dummy to suppress unused var warning
            if (jacobian__)
                betas = in__.vector_constrain(n_k, lp__);
            else
                betas = in__.vector_constrain(n_k);
            current_statement_begin__ = 12;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> inv_omegas;
            (void) inv_omegas;  // dummy to suppress unused var warning
            if (jacobian__)
                inv_omegas = in__.vector_lub_constrain(0, 1, n_k, lp__);
            else
                inv_omegas = in__.vector_lub_constrain(0, 1, n_k);
            current_statement_begin__ = 13;
            local_scalar_t__ sigma_alpha;
            (void) sigma_alpha;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma_alpha = in__.scalar_lb_constrain(0, lp__);
            else
                sigma_alpha = in__.scalar_lb_constrain(0);
            current_statement_begin__ = 14;
            local_scalar_t__ mu_beta;
            (void) mu_beta;  // dummy to suppress unused var warning
            if (jacobian__)
                mu_beta = in__.scalar_constrain(lp__);
            else
                mu_beta = in__.scalar_constrain();
            current_statement_begin__ = 15;
            local_scalar_t__ sigma_beta;
            (void) sigma_beta;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma_beta = in__.scalar_lb_constrain(0, lp__);
            else
                sigma_beta = in__.scalar_lb_constrain(0);
            // transformed parameters
            current_statement_begin__ = 19;
            validate_non_negative_index("omegas", "n_k", n_k);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> omegas(n_k);
            stan::math::initialize(omegas, DUMMY_VAR__);
            stan::math::fill(omegas, DUMMY_VAR__);
            stan::math::assign(omegas,elt_divide(1.0, inv_omegas));
            current_statement_begin__ = 20;
            validate_non_negative_index("par1", "n_i", n_i);
            validate_non_negative_index("par1", "n_k", n_k);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, Eigen::Dynamic> par1(n_i, n_k);
            stan::math::initialize(par1, DUMMY_VAR__);
            stan::math::fill(par1, DUMMY_VAR__);
            current_statement_begin__ = 21;
            validate_non_negative_index("par2", "n_k", n_k);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> par2(n_k);
            stan::math::initialize(par2, DUMMY_VAR__);
            stan::math::fill(par2, DUMMY_VAR__);
            // transformed parameters block statements
            current_statement_begin__ = 23;
            for (int i = 1; i <= n_i; ++i) {
                current_statement_begin__ = 24;
                for (int k = 1; k <= n_k; ++k) {
                    current_statement_begin__ = 25;
                    stan::model::assign(par1, 
                                stan::model::cons_list(stan::model::index_uni(i), stan::model::cons_list(stan::model::index_uni(k), stan::model::nil_index_list())), 
                                (stan::math::exp((get_base1(alphas, i, "alphas", 1) + get_base1(betas, k, "betas", 1))) / (get_base1(omegas, k, "omegas", 1) - 1.0)), 
                                "assigning variable par1");
                }
            }
            current_statement_begin__ = 29;
            for (int k = 1; k <= n_k; ++k) {
                current_statement_begin__ = 30;
                stan::model::assign(par2, 
                            stan::model::cons_list(stan::model::index_uni(k), stan::model::nil_index_list()), 
                            (1.0 / (get_base1(omegas, k, "omegas", 1) - 1.0)), 
                            "assigning variable par2");
            }
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 19;
            size_t omegas_j_1_max__ = n_k;
            for (size_t j_1__ = 0; j_1__ < omegas_j_1_max__; ++j_1__) {
                if (stan::math::is_uninitialized(omegas(j_1__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: omegas" << "(" << j_1__ << ")";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable omegas: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            check_greater_or_equal(function__, "omegas", omegas, 0);
            current_statement_begin__ = 20;
            size_t par1_j_1_max__ = n_i;
            size_t par1_j_2_max__ = n_k;
            for (size_t j_1__ = 0; j_1__ < par1_j_1_max__; ++j_1__) {
                for (size_t j_2__ = 0; j_2__ < par1_j_2_max__; ++j_2__) {
                    if (stan::math::is_uninitialized(par1(j_1__, j_2__))) {
                        std::stringstream msg__;
                        msg__ << "Undefined transformed parameter: par1" << "(" << j_1__ << ", " << j_2__ << ")";
                        stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable par1: ") + msg__.str()), current_statement_begin__, prog_reader__());
                    }
                }
            }
            check_greater_or_equal(function__, "par1", par1, 0);
            current_statement_begin__ = 21;
            size_t par2_j_1_max__ = n_k;
            for (size_t j_1__ = 0; j_1__ < par2_j_1_max__; ++j_1__) {
                if (stan::math::is_uninitialized(par2(j_1__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: par2" << "(" << j_1__ << ")";
                    stan::lang::rethrow_located(std::runtime_error(std::string("Error initializing variable par2: ") + msg__.str()), current_statement_begin__, prog_reader__());
                }
            }
            check_greater_or_equal(function__, "par2", par2, 0);
            // model body
            current_statement_begin__ = 35;
            lp_accum__.add(normal_log<propto__>(alphas, 0, sigma_alpha));
            current_statement_begin__ = 36;
            lp_accum__.add(normal_log<propto__>(betas, mu_beta, sigma_beta));
            current_statement_begin__ = 38;
            for (int k = 1; k <= n_k; ++k) {
                current_statement_begin__ = 39;
                for (int i = 1; i <= n_i; ++i) {
                    current_statement_begin__ = 40;
                    lp_accum__.add(neg_binomial_log<propto__>(get_base1(get_base1(y, i, "y", 1), k, "y", 2), get_base1(par1, i, k, "par1", 1), get_base1(par2, k, "par2", 1)));
                }
            }
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
        lp_accum__.add(lp__);
        return lp_accum__.sum();
    } // log_prob()
    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }
    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("alphas");
        names__.push_back("betas");
        names__.push_back("inv_omegas");
        names__.push_back("sigma_alpha");
        names__.push_back("mu_beta");
        names__.push_back("sigma_beta");
        names__.push_back("omegas");
        names__.push_back("par1");
        names__.push_back("par2");
    }
    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(n_i);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(n_k);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(n_k);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(n_k);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(n_i);
        dims__.push_back(n_k);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(n_k);
        dimss__.push_back(dims__);
    }
    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;
        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "model_Overdispersed_Stan_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        Eigen::Matrix<double, Eigen::Dynamic, 1> alphas = in__.vector_constrain(n_i);
        size_t alphas_j_1_max__ = n_i;
        for (size_t j_1__ = 0; j_1__ < alphas_j_1_max__; ++j_1__) {
            vars__.push_back(alphas(j_1__));
        }
        Eigen::Matrix<double, Eigen::Dynamic, 1> betas = in__.vector_constrain(n_k);
        size_t betas_j_1_max__ = n_k;
        for (size_t j_1__ = 0; j_1__ < betas_j_1_max__; ++j_1__) {
            vars__.push_back(betas(j_1__));
        }
        Eigen::Matrix<double, Eigen::Dynamic, 1> inv_omegas = in__.vector_lub_constrain(0, 1, n_k);
        size_t inv_omegas_j_1_max__ = n_k;
        for (size_t j_1__ = 0; j_1__ < inv_omegas_j_1_max__; ++j_1__) {
            vars__.push_back(inv_omegas(j_1__));
        }
        double sigma_alpha = in__.scalar_lb_constrain(0);
        vars__.push_back(sigma_alpha);
        double mu_beta = in__.scalar_constrain();
        vars__.push_back(mu_beta);
        double sigma_beta = in__.scalar_lb_constrain(0);
        vars__.push_back(sigma_beta);
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        if (!include_tparams__ && !include_gqs__) return;
        try {
            // declare and define transformed parameters
            current_statement_begin__ = 19;
            validate_non_negative_index("omegas", "n_k", n_k);
            Eigen::Matrix<double, Eigen::Dynamic, 1> omegas(n_k);
            stan::math::initialize(omegas, DUMMY_VAR__);
            stan::math::fill(omegas, DUMMY_VAR__);
            stan::math::assign(omegas,elt_divide(1.0, inv_omegas));
            current_statement_begin__ = 20;
            validate_non_negative_index("par1", "n_i", n_i);
            validate_non_negative_index("par1", "n_k", n_k);
            Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> par1(n_i, n_k);
            stan::math::initialize(par1, DUMMY_VAR__);
            stan::math::fill(par1, DUMMY_VAR__);
            current_statement_begin__ = 21;
            validate_non_negative_index("par2", "n_k", n_k);
            Eigen::Matrix<double, Eigen::Dynamic, 1> par2(n_k);
            stan::math::initialize(par2, DUMMY_VAR__);
            stan::math::fill(par2, DUMMY_VAR__);
            // do transformed parameters statements
            current_statement_begin__ = 23;
            for (int i = 1; i <= n_i; ++i) {
                current_statement_begin__ = 24;
                for (int k = 1; k <= n_k; ++k) {
                    current_statement_begin__ = 25;
                    stan::model::assign(par1, 
                                stan::model::cons_list(stan::model::index_uni(i), stan::model::cons_list(stan::model::index_uni(k), stan::model::nil_index_list())), 
                                (stan::math::exp((get_base1(alphas, i, "alphas", 1) + get_base1(betas, k, "betas", 1))) / (get_base1(omegas, k, "omegas", 1) - 1.0)), 
                                "assigning variable par1");
                }
            }
            current_statement_begin__ = 29;
            for (int k = 1; k <= n_k; ++k) {
                current_statement_begin__ = 30;
                stan::model::assign(par2, 
                            stan::model::cons_list(stan::model::index_uni(k), stan::model::nil_index_list()), 
                            (1.0 / (get_base1(omegas, k, "omegas", 1) - 1.0)), 
                            "assigning variable par2");
            }
            if (!include_gqs__ && !include_tparams__) return;
            // validate transformed parameters
            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 19;
            check_greater_or_equal(function__, "omegas", omegas, 0);
            current_statement_begin__ = 20;
            check_greater_or_equal(function__, "par1", par1, 0);
            current_statement_begin__ = 21;
            check_greater_or_equal(function__, "par2", par2, 0);
            // write transformed parameters
            if (include_tparams__) {
                size_t omegas_j_1_max__ = n_k;
                for (size_t j_1__ = 0; j_1__ < omegas_j_1_max__; ++j_1__) {
                    vars__.push_back(omegas(j_1__));
                }
                size_t par1_j_2_max__ = n_k;
                size_t par1_j_1_max__ = n_i;
                for (size_t j_2__ = 0; j_2__ < par1_j_2_max__; ++j_2__) {
                    for (size_t j_1__ = 0; j_1__ < par1_j_1_max__; ++j_1__) {
                        vars__.push_back(par1(j_1__, j_2__));
                    }
                }
                size_t par2_j_1_max__ = n_k;
                for (size_t j_1__ = 0; j_1__ < par2_j_1_max__; ++j_1__) {
                    vars__.push_back(par2(j_1__));
                }
            }
            if (!include_gqs__) return;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }
    std::string model_name() const {
        return "model_Overdispersed_Stan";
    }
    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t alphas_j_1_max__ = n_i;
        for (size_t j_1__ = 0; j_1__ < alphas_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "alphas" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t betas_j_1_max__ = n_k;
        for (size_t j_1__ = 0; j_1__ < betas_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "betas" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t inv_omegas_j_1_max__ = n_k;
        for (size_t j_1__ = 0; j_1__ < inv_omegas_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "inv_omegas" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_alpha";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu_beta";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_beta";
        param_names__.push_back(param_name_stream__.str());
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t omegas_j_1_max__ = n_k;
            for (size_t j_1__ = 0; j_1__ < omegas_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "omegas" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t par1_j_2_max__ = n_k;
            size_t par1_j_1_max__ = n_i;
            for (size_t j_2__ = 0; j_2__ < par1_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < par1_j_1_max__; ++j_1__) {
                    param_name_stream__.str(std::string());
                    param_name_stream__ << "par1" << '.' << j_1__ + 1 << '.' << j_2__ + 1;
                    param_names__.push_back(param_name_stream__.str());
                }
            }
            size_t par2_j_1_max__ = n_k;
            for (size_t j_1__ = 0; j_1__ < par2_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "par2" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        if (!include_gqs__) return;
    }
    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t alphas_j_1_max__ = n_i;
        for (size_t j_1__ = 0; j_1__ < alphas_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "alphas" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t betas_j_1_max__ = n_k;
        for (size_t j_1__ = 0; j_1__ < betas_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "betas" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        size_t inv_omegas_j_1_max__ = n_k;
        for (size_t j_1__ = 0; j_1__ < inv_omegas_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "inv_omegas" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_alpha";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu_beta";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_beta";
        param_names__.push_back(param_name_stream__.str());
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
            size_t omegas_j_1_max__ = n_k;
            for (size_t j_1__ = 0; j_1__ < omegas_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "omegas" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
            size_t par1_j_2_max__ = n_k;
            size_t par1_j_1_max__ = n_i;
            for (size_t j_2__ = 0; j_2__ < par1_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < par1_j_1_max__; ++j_1__) {
                    param_name_stream__.str(std::string());
                    param_name_stream__ << "par1" << '.' << j_1__ + 1 << '.' << j_2__ + 1;
                    param_names__.push_back(param_name_stream__.str());
                }
            }
            size_t par2_j_1_max__ = n_k;
            for (size_t j_1__ = 0; j_1__ < par2_j_1_max__; ++j_1__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "par2" << '.' << j_1__ + 1;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        if (!include_gqs__) return;
    }
}; // model
}  // namespace
typedef model_Overdispersed_Stan_namespace::model_Overdispersed_Stan stan_model;
#ifndef USING_R
stan::model::model_base& new_model(
        stan::io::var_context& data_context,
        unsigned int seed,
        std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}
#endif
#endif
