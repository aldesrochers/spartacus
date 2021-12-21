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
#include <string>
using namespace std;

// Mercury
#include <Mercury_Utilities.hxx>



// ============================================================================
/*!
 *  \brief decryptString()
*/
// ============================================================================
QString Mercury_Utilities::decryptString(const QString &theEncryptedString)
{
    return encryptDecrypt(theEncryptedString);
}

// ============================================================================
/*!
 *  \brief defaultUserExpirationDate()
 *  Retrieve the default user expiration user. Use 2100/01/01 trivially.
*/
// ============================================================================
QDateTime Mercury_Utilities::defaultUserExpirationDate()
{
    QDate aDate(2100, 1, 1);
    return QDateTime(aDate, QTime());
}

// ============================================================================
/*!
 *  \brief encryptDecrypt()
 *  Simple XOR encryption algorithm for strings.
*/
// ============================================================================
QString Mercury_Utilities::encryptDecrypt(const QString &theString)
{
    char key[3] = {'A', 'L', 'D'};
    string anInput = theString.toStdString();
    string anOutput = theString.toStdString();
    for (int i = 0; i < anInput.size(); i++)
        anOutput[i] = anInput[i] ^ key[i % (sizeof(key) / sizeof(char))];
    return QString::fromStdString(anOutput);
}

// ============================================================================
/*!
 *  \brief encryptString()
*/
// ============================================================================
QString Mercury_Utilities::encryptString(const QString &theString)
{
    return encryptDecrypt(theString);
}
