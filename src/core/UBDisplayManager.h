/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef UBDISPLAYMANAGER_H_
#define UBDISPLAYMANAGER_H_

#include <QtGui>

class UBBlackoutWidget;
class UBBoardView;

class UBDisplayManager : public QObject
{
    Q_OBJECT;

    public:
        UBDisplayManager(QObject *parent = 0);
        virtual ~UBDisplayManager();

        int numScreens();

        int numPreviousViews();

        void setAsControl(QWidget* pControlWidget, bool init = false);

        void setAsDisplay(QWidget* pDisplayWidget);

        void setAsDesktop(QWidget* pControlWidget);

        void setAsPreviousDisplays(QList<UBBoardView*> pPreviousViews);

        bool hasControl()
        {
            return mControlScreenIndex > -1;
        }

        bool hasDisplay()
        {
            return mDisplayScreenIndex > -1;
        }

        bool hasPrevious()
        {
            return !mPreviousScreenIndexes.isEmpty();
        }

        enum DisplayRole
        {
            None = 0, Control, Display, Previous1, Previous2, Previous3, Previous4, Previous5
        };

        void setUseMultiScreen(bool pUse);

        int controleScreenIndex()
        {
            return mControlScreenIndex;
        }

        QRect controlGeometry();
        QRect displayGeometry();

   signals:

           void screenLayoutChanged();

   public slots:

        void swapScreens(bool bswap);

        void adjustScreens(int screen);

        void blackout();

        void unBlackout();

        void setRoleToScreen(DisplayRole role, int screenIndex);

    private:

        void positionScreens();

        void initScreenIndexes();

        int mControlScreenIndex;

        int mDisplayScreenIndex;

        QList<int> mPreviousScreenIndexes;

        QDesktopWidget* mDesktop;

        QWidget* mControlWidget;

        QWidget* mDisplayWidget;

        QWidget *mDesktopWidget;

        QList<UBBoardView*> mPreviousDisplayWidgets;

        QList<UBBlackoutWidget*> mBlackoutWidgets;

        QList<DisplayRole> mScreenIndexesRoles;

        bool mUseMultiScreen;

};

#endif /* UBDISPLAYMANAGER_H_ */
