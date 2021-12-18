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
#include <Mercury_TableView.hxx>


// ============================================================================
/*!
 *  \brief Constructor
*/
// ============================================================================
Mercury_TableView::Mercury_TableView(QWidget* theParent)
    : QTableView(theParent)
{

}

// ============================================================================
/*!
 *  \brief Destructor
*/
// ============================================================================
Mercury_TableView::~Mercury_TableView()
{

}

// ============================================================================
/*!
 *  \brief createPopupMenu()
*/
// ============================================================================
QMenu* Mercury_TableView::createPopupMenu()
{
    QMenu* aMenu = new QMenu(this);
    QAction* addAction = aMenu->addAction(tr("Add"));
    connect(addAction, SIGNAL(triggered(bool)), this, SLOT(insertRecord()));
    QAction* submitAction = aMenu->addAction(tr("Submit"));
    connect(submitAction, SIGNAL(triggered(bool)), model(), SLOT(submitAll()));
    return aMenu;
}

// ============================================================================
/*!
 *  \brief insertRecord()
*/
// ============================================================================
void Mercury_TableView::insertRecord()
{
    cout << model()->insertRow(0) << endl;
}

// ============================================================================
/*!
 *  \brief mousePressEvent()
*/
// ============================================================================
void Mercury_TableView::mousePressEvent(QMouseEvent *theEvent)
{
    if(theEvent->button() == Qt::RightButton) {
        QPoint aPosition = mapToGlobal(theEvent->pos());
        QMenu* aMenu = createPopupMenu();
        aMenu->exec(aPosition);
    }
}
