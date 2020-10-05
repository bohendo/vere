import React, { Component } from 'react';
import { ChannelSidebar } from './lib/channel-sidebar';
import ErrorBoundary from '~/views/components/ErrorBoundary';

export class Skeleton extends Component {
  render() {
    const { props } = this;
    const rightPanelHide = props.rightPanelHide ? 'dn-s' : '';

    const linkInvites = ('/link' in props.invites)
      ? props.invites['/link'] : {};

    return (
      <div className='absolute w-100 ph4-m ph4-l ph4-xl pb4-m pb4-l pb4-xl'
           style={{ height: 'calc(100% - 45px)' }}>
        <div className='bg-white bg-gray0-d cf w-100 h-100 flex ba-m ba-l ba-xl b--gray4 b--gray1-d br1'>
        <ChannelSidebar
          active={props.active}
          associations={props.associations}
          invites={linkInvites}
          groups={props.groups}
          selected={props.selected}
          sidebarShown={props.sidebarShown}
          api={props.api}
          graphKeys={props.graphKeys} />
          <div className={'h-100 w-100 flex-auto relative ' + rightPanelHide}
               style={{ flexGrow: 1 }}>
            <ErrorBoundary>
              {props.children}
            </ErrorBoundary>
          </div>
        </div>
      </div>
    );
  }
}
