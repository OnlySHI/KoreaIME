#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    void shiftAllBtn();
    void setHungulDisplay(QString &keycode);

private slots:
    void on_q_clicked();
    void on_w_clicked();

    void on_e_clicked();

    void on_r_clicked();

    void on_t_clicked();

    void on_y_clicked();

    void on_u_clicked();

    void on_i_clicked();

    void on_o_clicked();

    void on_p_clicked();

    void on_a_clicked();

    void on_s_clicked();

    void on_d_clicked();

    void on_f_clicked();

    void on_g_clicked();

    void on_h_clicked();

    void on_j_clicked();

    void on_k_clicked();

    void on_l_clicked();

    void on_z_clicked();

    void on_x_clicked();

    void on_c_clicked();

    void on_v_clicked();

    void on_b_clicked();

    void on_n_clicked();

    void on_m_clicked();

    void on_shift_clicked();

    void on_space_clicked();

    void on_backspace_clicked();

private:
    Ui::Widget *ui;

    bool shift;
};

#endif // WIDGET_H
