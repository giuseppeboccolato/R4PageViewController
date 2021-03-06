/*
//  R4PageViewController.h
//  R4PageViewController
//
//  Created by Srđan Rašić on 9/8/13.

The MIT License (MIT)

Copyright (c) 2013 Srđan Rašić

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#import <UIKit/UIKit.h>

@class R4PageViewController;


//! Default: [UIColor blackColor]
extern NSString * const R4OptionFrontPageShadowColor;

//! Default: [NSNumber numberWithFloat:0.2]
extern NSString * const R4OptionFrontPageShadowOpacity;

//! Default: [NSNumber numberWithFloat:4]
extern NSString * const R4OptionFrontPageShadowRadius;

//! Default: [NSValue valueWithUIEdgeInsets:UIEdgeInsetsMake(0, 0, 0, 0)]
extern NSString * const R4OptionFrontPageInsets;

//! Default: [NSNumber numberWithFloat:0.7]
extern NSString * const R4OptionSidePagesSpaceDelayRate;

//! Default: [NSNumber numberWithInteger:50]
extern NSString * const R4OptionBorderPageMaxIndent;

//! Default: [NSNumber numberWithInteger:R4PreloadLevelPreload]
extern NSString * const R4OptionPreloadLevel;


typedef enum {
  
  //! Load previous/next when needed (when revealing starts). Release when not needed. Keeps only current view controller in memory.
  R4PreloadLevelLoadAndRelease,
  
  //! Load previous/next when needed (when revealing starts) and keep cached while they stay being previous/current/next.
  R4PreloadLevelLoadAndKeep,
  
  //! Preload previous and next view controller. Previous, current and next view controller are always cached in memory.
  R4PreloadLevelPreload
  
} R4PreloadLevel;


//! Implement this protocol to provide data for R4PageViewController.
@protocol R4PageViewControllerDataSource <NSObject>

@required
- (NSInteger)numberOfPagesInPageViewController:(R4PageViewController *)pageViewController;
- (UIViewController *)pageViewController:(R4PageViewController *)pageViewController viewControllerForPage:(NSInteger)page;

@end



//! Get informed of state changes through delegate.
@protocol R4PageViewControllerDelegate <NSObject>

@optional
- (void)pageViewController:(R4PageViewController *)pageViewController willScrollToPage:(NSInteger)toPage toController:(UIViewController *)toController;
- (void)pageViewController:(R4PageViewController *)pageViewController didScrollToPage:(NSInteger)toPage toController:(UIViewController *)toController;
- (void)pageViewController:(R4PageViewController *)pageViewController didTapOnPage:(NSInteger)page controller:(UIViewController *)controller;
- (void)pageViewController:(R4PageViewController *)pageViewController didScrollToOffset:(CGFloat)offset;

@end



//! R4PageViewController main class.
@interface R4PageViewController : UIViewController

@property (weak, nonatomic) id<R4PageViewControllerDataSource> dataSource;
@property (weak, nonatomic) id<R4PageViewControllerDelegate> delegate;
@property (strong, nonatomic, readonly) UIViewController *currentViewController;
@property (assign, nonatomic) NSInteger currentPage;

// Methods
- (id)initWithOptions:(NSDictionary *)options;
- (void)reloadData;

@end

