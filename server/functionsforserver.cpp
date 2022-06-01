/*!
 * \file
 */

#include "functionsforserver.h"





/*!
 * \brief parsing - функция, которая по введённому названию комманды и дополнительным параметрам запускает команду и возращает
 * результат работы.
 * \param [in] data_from_client - строка, которая приходит от клиента в формате func&param1&param2...paramN.
 * \return возвращает результат работы команды, поданной на вход.
*/
QByteArray parsing(QString data_from_client){
    QStringList data_from_client_list = data_from_client.split(QLatin1Char('&'));
    QString nameOfFunc = data_from_client_list.front();
    data_from_client_list.pop_front();
   // qDebug() << nameOfFunc;

    qDebug() << data_from_client;
    if (nameOfFunc == "auth"){
        //change_sock_desc(data_from_client_list.at(0));
        return auth(data_from_client_list.at(0), data_from_client_list.at(1));}

    else if (nameOfFunc == "reg"){
        return reg(data_from_client_list.at(0), data_from_client_list.at(1));}

    else if (nameOfFunc == "getAll"){
        return all();}

    else if (nameOfFunc == "addEvent"){
            return addEvent(data_from_client_list.at(0),data_from_client_list.at(1),data_from_client_list.at(2),data_from_client_list.at(3),data_from_client_list.at(4),data_from_client_list.at(5),data_from_client_list.at(6),data_from_client_list.at(7),data_from_client_list.at(8));
    }
    else if (nameOfFunc == "getService"){
        return getService();}

    else if (nameOfFunc == "getControl"){
        return getControl();}
    else if (nameOfFunc == "getSplits"){
        return DataBase::getSplits();}
else

        return "error";

}

/*!
 * \brief auth - функция, которая реализует команду auth, нужная для аутентификации пользователя на сервере.
 * \param [in] log - строка, которая содержит логин пользователя.
 * \param [in] pass - строка, которая содержит пароль пользователя.
 * \return возвращает результат аутентификации.
*/
QByteArray auth(QString log, QString pass){
    QByteArray result = "";
    result.append(DataBase::auth(log, pass).toUtf8());
    qDebug() << result;
    return result;
}

/*!
 * \brief reg - функция, которая реализует команду reg, нужная для регистрации пользователя на сервере.
 * \param [in] log - строка, которая содержит логин пользователя.
 * \param [in] pass - строка, которая содержит пароль пользователя.
 * \param [in] mail - строка, которая содержит необязательный электронный адрес почты пользователя.
 * \return возвращает результат регистрации.
*/
QByteArray reg(QString log, QString pass){
    QByteArray result = "";
    result.append(DataBase::reg(log, pass).toUtf8());
    qDebug() << result;
    return result;
}


QByteArray all(){
    QByteArray result = "";
    result.append(DataBase::getAll().toUtf8());
    qDebug() << result;
    return result;
}

QByteArray addEvent(QString id, QString date, QString weather, QString duration, QString conf, QString type, QString split, QString control, QString service)
{
    QByteArray result;
    result.append(DataBase::addEvent(id,date, weather,  duration,  conf,  type,  split,  control,  service));
    return result;
}

QByteArray getService()
{
    QByteArray result;
    result.append(DataBase::getService());
    return result;
}

QByteArray getControl()
{
    QByteArray result;
    result.append(DataBase::getControl());
    return result;
}

