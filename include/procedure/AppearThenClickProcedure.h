//
// Created by pc on 2024/8/10.
//

#ifndef BAAS_PROCEDURE_APPEARTHENCLICKPROCEDURE_H_
#define BAAS_PROCEDURE_APPEARTHENCLICKPROCEDURE_H_


#define BAAS_PROCEDURE_TYPE_APPEAR_THEN_CLICK 0

#include "procedure/BaseProcedure.h"

class AppearThenClickProcedure : public BaseProcedure {
public:
    explicit AppearThenClickProcedure(BAASConfig* possible_features);

    void implement(BAAS* baas, BAASConfig& output) override;

    void clear_resource() override;
private:
    void wait_loading();

    void clear_possibles();

    void solve_feature_appear(BAASConfig* feature,bool show_log = false);

    void solve_feature_action_click(BAASConfig* parameters);

    void pop_last_clicked_queue(int size=0);

    void insert_last_clicked_queue(std::string& feature_name);

    std::vector<BAASConfig*> possibles;

    std::vector<std::string> possibles_feature_names;

    std::string last_clicked_feature_name;

    long long last_clicked_time;

    long long max_stuck_time;

    long long start_time;

    int max_click;

    std::queue<std::string> last_clicked;

    std::map<std::string, int> last_clicked_counter;                              // too many clicked

    std::string last_appeared_feature_name;

    long long last_appeared_time = 0;

    std::pair<std::pair<std::string, int>,std::pair<std::string, int>> last_clicked_pair_counter; // too many clicked between two features

    std::string current_comparing_feature_name;

    BAASConfig temp_output;

};

#endif //BAAS_PROCEDURE_APPEARTHENCLICKPROCEDURE_H_
