#ifndef WCOVERARTLABEL_H
#define WCOVERARTLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QWidget>
#include <QPixmap>

#include "widget/wcoverartmenu.h"

class DlgCoverArtFullSize;

class WCoverArtLabel : public QLabel {
    Q_OBJECT
  public:
    explicit WCoverArtLabel(QWidget* parent = nullptr);
    ~WCoverArtLabel() override;

    void setCoverArt(const QString& trackLocation, const CoverInfo& coverInfo, QPixmap px);

  signals:
    void coverArtSelected(const CoverArt& art);
    void reloadCoverArt();

  protected:
    void leaveEvent(QEvent* /*unused*/) override;
    void mousePressEvent(QMouseEvent* event) override;

  private slots:
      void slotCoverMenu(const QPoint& pos);

  private:
    CoverInfo m_coverInfo;
    WCoverArtMenu* m_pCoverMenu;
    DlgCoverArtFullSize* m_pDlgFullSize;
    QPixmap m_defaultCover;
};

#endif // WCOVERARTLABEL_H
