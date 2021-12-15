// ============================================================================
// Copyright (C) 2021-
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
//
// Alexis L. Desrochers (alexisdesrochers@gmail.com)
//
// ============================================================================

#include <iostream>
using namespace std;

// Mercury
#include <Mercury_UsersTableModel.hxx>
#include <Mercury_Utilities.hxx>

// Qt
#include <QCryptographicHash>


// ============================================================================
/*!
    \brief Constructor
*/
// ============================================================================
Mercury_UsersTableModel::Mercury_UsersTableModel(const QSqlDatabase& theDatabase,
                                                 QObject* theParent)
    : Mercury_TableModel(theDatabase, theParent)
{

}

// ============================================================================
/*!
    \brief Destructor
*/
// ============================================================================
Mercury_UsersTableModel::~Mercury_UsersTableModel()
{

}

// ============================================================================
/*!
 *  \brief createStatement()
*/
// ============================================================================
QString Mercury_UsersTableModel::createStatement() const
{
    QString aString;
    if(driverType() == Mercury_SQLiteDriver) {
        aString += QString("CREATE TABLE %1 (").arg(tableName());
        aString += "userName TEXT PRIMARY KEY, ";
        aString += "password TEXT, ";
        aString += "firstName TEXT, ";
        aString += "lastName TEXT, ";
        aString += "email TEXT, ";
        aString += "canCreateDatabases INTEGER NOT NULL, ";
        aString += "canCreateUsers INTEGER NOT NULL, ";
        aString += "canLogin INTEGER NOT NULL, ";
        aString += "isSuperUser INTEGER NOT NULL, ";
        aString += "creationDate TEXT, ";
        aString += "expirationDate TEXT, ";
        aString += "firstLogin TEXT, ";
        aString += "lastLogin TEXT)";
    } else if(driverType() == Mercury_PostgresDriver) {
        aString += QString("CREATE TABLE %1 (").arg(tableName());
        aString += "userName TEXT PRIMARY KEY, ";
        aString += "firstName TEXT, ";
        aString += "lastName TEXT, ";
        aString += "email TEXT, ";
        aString += "firstLogin TEXT, ";
        aString += "lastLogin TEXT)";
    }
    return aString;
}

// ==========================================================================
/*!
 *  \brief data()
*/
// ==========================================================================
QVariant Mercury_UsersTableModel::data(const QModelIndex &theIndex,
                                       int theRole) const
{
    if(driverType() == Mercury_SQLiteDriver) {
        if(theIndex.column() == 1) {
            // make sure to put an hash on password display/edit roles
            if(theRole == Qt::DisplayRole || theRole == Qt::EditRole) {
                QString anEncryptedPassword = QSqlTableModel::data(theIndex, theRole).toString();
                QString aPassword = Mercury_Utilities::decryptString(anEncryptedPassword);
                QCryptographicHash aHash(QCryptographicHash::Sha256);
                aHash.addData(aPassword.toStdString().c_str());
                return aHash.result();
            }
        }
    }
    return QSqlTableModel::data(theIndex, theRole);
}

// ============================================================================
/*!
 *  \brief setData()
*/
// ============================================================================
bool Mercury_UsersTableModel::setData(const QModelIndex &theIndex,
                                      const QVariant &theValue,
                                      int theRole)
{
    if(driverType() == Mercury_SQLiteDriver) {
        if(theIndex.column() ==  1) {
            // make sure to encrypt password before editing in database
            if(theRole == Qt::EditRole) {
                QString aPassword = theValue.toString();
                QString anEncryptedPassword = Mercury_Utilities::encryptString(aPassword);
                return QSqlTableModel::setData(theIndex, anEncryptedPassword, theRole);
            }
        }
    }
    return QSqlTableModel::setData(theIndex, theValue, theRole);
}
