#include "widget.h"
#include "ui_widget.h"
#include "hangulime.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    shift = false;
    ui->setupUi(this);
    ui->display->setReadOnly(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::shiftAllBtn()
{
    if(shift)
    {
        //如果按下了shift键
        ui->q->setText(QString(QChar(0x3143)));//'ㅃ'
        ui->w->setText(QString(QChar(0x3149)));//'ㅉ'
        ui->e->setText(QString(QChar(0x3138)));//'ㄸ'
        ui->r->setText(QString(QChar(0x3132)));//'ㄲ'
        ui->t->setText(QString(QChar(0x3146)));//'ㅆ'
        ui->o->setText(QString(QChar(0x3152)));//'ㅒ'
        ui->p->setText(QString(QChar(0x3156)));//'ㅖ'
    }
    else
    {
        //如果没有按下shift键
        ui->q->setText(QString(QChar(0x3142)));//'ㅂ'
        ui->w->setText(QString(QChar(0x3148)));//'ㅈ'
        ui->e->setText(QString(QChar(0x3137)));//'ㄷ'
        ui->r->setText(QString(QChar(0x3131)));//'ㄱ'
        ui->t->setText(QString(QChar(0x3145)));//'ㅅ'
        ui->o->setText(QString(QChar(0x3150)));//'ㅐ'
        ui->p->setText(QString(QChar(0x3154)));//'ㅔ'
    }
}

void Widget::setHungulDisplay(QString &keycode)
{
    //新按键字符不为空，而且是韩语基本字符
    if (!keycode.isEmpty() && isJamo(keycode.at(0).unicode()))
    {
        //定义输入参数，和输出参数
        unsigned short inputunicode[2] = { 0 };
        unsigned short outunicode[2] = { 0 };
        //获得显示框的显示内容
        QString text = ui->display->text();

        if (text.size() > 0)//如果显示框内容不是空的
        {
            //把显示框中最后一个字符取出来，设置到输入参数数组的第一个值中
            QString text1 = text.mid(text.size() - 1, 1);
            inputunicode[0] = text1.at(0).unicode();
        }
        else
        {
            //如果显示框内容为空，则把输入参数数组的第一个值设置为0
            inputunicode[0] = 0;
        }
        //把刚刚最新按的键的内容设置到输入参数数组的第二个值，例如‘ㅎ’
        inputunicode[1] = keycode.at(0).unicode();

        //调用库接口API
        int ret = hangulIME(inputunicode, outunicode);

        //如果返回值为1，只返回了一个字符，则说明输入的两个字符是可以组合的
        if (ret == 1)
        {
            text.chop(1);//把显示框中最后一个字符删除，替代成刚刚组合出来的最新的字符
            text.append(QChar(outunicode[0]));
        }
        else if (ret == 2)//如果返回值为2，返回了2个字符
        {
            text.chop(1);//把显示框中最后一个字符删除，显示框上追加输出来的两个字符
            text.append(QChar(outunicode[0]));
            text.append(QChar(outunicode[1]));
        }
        else//这种情况下，也就是说无法进行组合，显示框最后一个字符可能不是韩语字符
        {
            text.append(keycode);//所以只要往显示框追加新按键的字符就行了
        }
        //显示输出
        ui->display->setText(text);
    }
}

void Widget::on_q_clicked()
{
    setHungulDisplay(ui->q->text());
}

void Widget::on_w_clicked()
{
    setHungulDisplay(ui->w->text());
}

void Widget::on_e_clicked()
{
    setHungulDisplay(ui->e->text());
}

void Widget::on_r_clicked()
{
    setHungulDisplay(ui->r->text());
}

void Widget::on_t_clicked()
{
    setHungulDisplay(ui->t->text());
}

void Widget::on_y_clicked()
{
    setHungulDisplay(ui->y->text());
}

void Widget::on_u_clicked()
{
    setHungulDisplay(ui->u->text());
}

void Widget::on_i_clicked()
{
    setHungulDisplay(ui->i->text());
}

void Widget::on_o_clicked()
{
    setHungulDisplay(ui->o->text());
}

void Widget::on_p_clicked()
{
    setHungulDisplay(ui->p->text());
}

void Widget::on_a_clicked()
{
    setHungulDisplay(ui->a->text());
}

void Widget::on_s_clicked()
{
    setHungulDisplay(ui->s->text());
}

void Widget::on_d_clicked()
{
    setHungulDisplay(ui->d->text());
}

void Widget::on_f_clicked()
{
    setHungulDisplay(ui->f->text());
}

void Widget::on_g_clicked()
{
    //拿到按钮上的文本‘ㅎ’，调用函数setHungulDisplay
    setHungulDisplay(ui->g->text());
}

void Widget::on_h_clicked()
{
    setHungulDisplay(ui->h->text());
}

void Widget::on_j_clicked()
{
    setHungulDisplay(ui->j->text());
}

void Widget::on_k_clicked()
{
    setHungulDisplay(ui->k->text());
}

void Widget::on_l_clicked()
{
    setHungulDisplay(ui->l->text());
}

void Widget::on_z_clicked()
{
    setHungulDisplay(ui->z->text());
}

void Widget::on_x_clicked()
{
    setHungulDisplay(ui->x->text());
}

void Widget::on_c_clicked()
{
    setHungulDisplay(ui->c->text());
}

void Widget::on_v_clicked()
{
    setHungulDisplay(ui->v->text());
}

void Widget::on_b_clicked()
{
    setHungulDisplay(ui->b->text());
}

void Widget::on_n_clicked()
{
    setHungulDisplay(ui->n->text());
}

void Widget::on_m_clicked()
{
    setHungulDisplay(ui->m->text());
}

void Widget::on_shift_clicked()
{
    shift = !shift;
    shiftAllBtn();
}

void Widget::on_space_clicked()
{
    QString text = ui->display->text();
    text.append(" ");
    ui->display->setText(text);
}

void Widget::on_backspace_clicked()
{
    QString text = ui->display->text();
    text.chop(1);
    ui->display->setText(text);
}
